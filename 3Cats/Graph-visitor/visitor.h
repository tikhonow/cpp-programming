#pragma once
#include <memory>
template<class Vertex>
class BfsVisitor {
public:
    BfsVisitor() {
        a = std::make_shared<Grag>();
        a->v = 222222222 ;
    }
    void ExamineVertex(const Vertex& vertex) {
        if (a->v == 222222222) {
            a->v = Vertex(vertex);
            return;
        }
        a->v = vertex;
    }
    void DiscoverVertex(const Vertex& vertex) {
        if (a->v == 222222222) {
            a->p.insert({ vertex, vertex });
            return;
        }
        a->p.insert({ vertex, a->v });
    }
    size_t DistanceTo(const Vertex& target) const {
        size_t path = 0;
        for (Vertex i = target;  i != a->p.at(i); i = a->p.at(i))
            path++;
        return path;
    }
    Vertex Parent(const Vertex& vertex) const {
        return a->p.at(vertex);
    }

private:
    struct Grag {
    public:
        Vertex v;
        std::unordered_map<Vertex, Vertex> p;
    };
    std::shared_ptr<Grag>a;
};

