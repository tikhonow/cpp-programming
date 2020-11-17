#pragma once
class BufferedReader {
 public:
  explicit BufferedReader(PackageStream* stream) {
    str = stream;
    buffer = new char[str->PackageLen()];
    pos = 0;
    sizeBuf = 0;
  }
  int32_t Read(char* output_buffer, int32_t buffer_len) {
    int32_t sizeinit = buffer_len;
    int32_t indstr = 0;
    while (buffer_len > 0) {
      if (pos == sizeBuf) {
        sizeBuf = str->ReadPackage(buffer);
        pos = 0;
        if (sizeBuf == 0) {
          delete[] buffer;
          return sizeinit - buffer_len;
        }
      }
      if (sizeBuf - pos < buffer_len) {
        memcpy(output_buffer + indstr, buffer + pos, sizeBuf - pos);
        indstr += sizeBuf - pos;
        buffer_len -= (sizeBuf - pos);
        pos = 0;
        sizeBuf = str->ReadPackage(buffer);
        if (sizeBuf == 0) {
          delete[] buffer;
          return sizeinit - buffer_len;
        }
      } else {
        memcpy(output_buffer + indstr, buffer + pos, buffer_len);
        pos += buffer_len;
        buffer_len = 0;
      }
    }
    return sizeinit;
  }

 private:
  int32_t pos, sizeBuf;
  char* buffer;
  PackageStream* str;
};
