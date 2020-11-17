#include <string>
#include <vector>

class FormatVisitor : public BaseVisitor {
 public:
  void Visit(const BaseNode *node) override {
    node->Visit(this);
  }

  void Visit(const ClassDeclarationNode *node) override {
    formatted.push_back(str + "class "
                            + node->ClassName() + " {");

    if (!node->PublicFields().empty()) {
      formatted.push_back(str + "  public:");
      str += "    ";
      for (unsigned int i = 0; i < node->PublicFields().size(); i++) {
        node->PublicFields()[i]->Visit(this);
        formatted[formatted.size() - 1] += ";";
      }

      str = str.substr(0, str.size() - 4);
    }

    if (!node->ProtectedFields().empty()) {
      formatted.push_back("");
      formatted.push_back(str + "  protected:");
      str += "    ";
      for (uint i = 0; i < node->ProtectedFields().size(); i++) {
        node->ProtectedFields()[i]->Visit(this);
        formatted[formatted.size() - 1] += ";";
      }
      str = str.substr(0, str.size() - 4);
    }

    if (!node->PrivateFields().empty()) {
      formatted.push_back("");
      formatted.push_back(str + "  private:");
      str += "    ";
      for (uint i = 0; i < node->PrivateFields().size(); i++) {
        node->PrivateFields()[i]->Visit(this);
        formatted[formatted.size() - 1] += ";";
      }
      str = str.substr(0, str.size() - 4);
    }
    formatted.push_back(str + "}");
    if (str == "") {
      formatted[formatted.size() - 1] += ";";
    }
  }
  void Visit(const VarDeclarationNode *node) override {
    formatted.push_back(str + node->TypeName()
                            + " " + node->VarName());
  }
  void Visit(const MethodDeclarationNode *node) override {
    formatted.push_back(str + node->ReturnTypeName()
                            + " " + node->MethodName() + "(");
    for (unsigned int i = 0; i < node->Arguments().size(); i++) {
      Visit(node->Arguments()[i]);
      formatted[formatted.size() - 2] +=
          formatted[formatted.size() - 1].substr(str.size(),
                                                 formatted[formatted.size() - 1].size()
                                                     - str.size());
      if (i < node->Arguments().size() - 1) {
        formatted[formatted.size() - 2] += ", ";
      }
      formatted.pop_back();
    }
    formatted[formatted.size() - 1] += ")";
  }

  const std::vector<std::string> &GetFormattedCode() const {
    return formatted;
  }

 private:
  std::string str = "";
  std::vector<std::string> formatted;
};