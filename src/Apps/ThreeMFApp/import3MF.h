#ifndef IMPORT_3MF_H
#define IMPORT_3MF_H

#include <string>
#include <vector>
#include <memory>

namespace E3D
{
    class Import3MF;

    class MeshModel;
    using PMeshModel = std::shared_ptr<MeshModel>;

    class Texture2D;
    using PTexture = std::shared_ptr<Texture2D>;

    using MeshModels = std::vector<PMeshModel>;
}

class E3D::Import3MF
{
public:
    Import3MF( const std::wstring& );
    ~Import3MF() = default;

    MeshModels meshModels() const;

    PTexture packageIcon() const { return m_packageIcon; }

private:
    Import3MF( const Import3MF& ) = delete;
    Import3MF& operator=( const Import3MF& ) = delete;

    bool readData( const std::wstring& );

private:
    MeshModels m_meshModels;

    PTexture m_packageIcon;
};

#endif //IMPORT_3MF_H
