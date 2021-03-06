#ifndef MESH_MODEL_H
#define MESH_MODEL_H

#include <Camera.h>
#include <MeshData.h>
#include <MeshDraw.h>

#include <string>
#include <vector>

namespace E3D
{
    class MeshModel;
    class Camera;
    class ShaderLoaderGL;
}

class E3D::MeshModel : public MeshDraw
{
public:
    MeshModel(const MeshData&);
    ~MeshModel();

    void draw(std::shared_ptr<Camera>&, std::shared_ptr<ShaderLoaderGL>&) override;

    void setName(const std::string&);
    std::string getName() const;

    uint32_t getNumVertices() const;
    uint32_t getNumTriangles() const;

protected:
    void sendDataToGPU() override;
    void updatMatrices(std::shared_ptr<Camera>&, std::shared_ptr<ShaderLoaderGL>&) override;

private:
    MeshData m_meshData;

    std::string m_name;
};

#endif //MESH_MODEL_H
