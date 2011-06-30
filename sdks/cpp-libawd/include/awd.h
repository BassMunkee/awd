#ifndef _LIBAWD_AWD_H
#define _LIBAWD_AWD_H

#include "awd_types.h"
#include "ns.h"
#include "block.h"
#include "attr.h"
#include "material.h"
#include "mesh.h"
#include "skeleton.h"
#include "skelanim.h"
#include "texture.h"
#include "uvanim.h"
#include "scene.h"


#define AWD_VERSION_MAJOR 2
#define AWD_VERSION_MINOR 0
#define AWD_VERSION_BUILD 0
#define AWD_VERSION_RELEASE 'a'

#define AWD_STREAMING               0x1
#define AWD_OPTIMIZE_FOR_ACCURACY   0x2

class AWD
{
    private:
        // File header fields
        awd_uint8 major_version;
        awd_uint8 minor_version;
        awd_uint16 flags;
        AWD_compression compression;

        AWDBlockList * namespace_blocks;
        AWDBlockList * texture_blocks;
        AWDBlockList * material_blocks;
        AWDBlockList * skelpose_blocks;
        AWDBlockList * skelanim_blocks;
        AWDBlockList * skeleton_blocks;
        AWDBlockList * mesh_data_blocks;
        AWDBlockList * uvanim_blocks;
        AWDBlockList * scene_blocks;

        // Flags and misc
        awd_baddr last_used_baddr;
        awd_nsid last_used_nsid;
        awd_bool header_written;

        void write_header(int, awd_uint32);
        void flatten_scene(AWDSceneBlock *, AWDBlockList *);
        size_t write_scene(AWDBlockList *, int);
        size_t write_blocks(AWDBlockList *, int);

    public:
        AWD(AWD_compression, awd_uint16);
        ~AWD();
        awd_uint32 flush(int);

        void add_texture(AWDTexture *);
        void add_material(AWDSimpleMaterial *);
        void add_mesh_data(AWDMeshData *);
        void add_skeleton(AWDSkeleton *);
        void add_skeleton_pose(AWDSkeletonPose *);
        void add_skeleton_anim(AWDSkeletonAnimation *);
        void add_uv_anim(AWDUVAnimation *);
        void add_scene_block(AWDSceneBlock *);
        void add_namespace(AWDNamespace *);
};


#endif
