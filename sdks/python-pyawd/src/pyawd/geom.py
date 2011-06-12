from pyawd import core

STR_VERTICES = 1
STR_TRIANGLES = 2
STR_UVS = 3
STR_VERTEX_NORMALS = 4
STR_VERTEX_TANGENTS = 5
STR_FACE_NORMALS = 6
STR_JOINT_INDICES = 7
STR_JOINT_WEIGHTS = 8

class AWDSubMesh:
    def __init__(self):
        self.__data_streams = []

    def add_stream(self, type, data):
        self.__data_streams.append((type,data))


class AWDMeshData(core.AWDAttrElement, core.AWDBlockBase):
    def __init__(self, name=''):
        super(AWDMeshData, self).__init__()

        self.name = name
        self.__sub_meshes = []

    def add_sub_mesh(self, sub):
        self.__sub_meshes.append(sub)

    def __len__(self):
        return len(self.__sub_meshes)

    def __getitem__(self, index):
        return self.__sub_meshes[index]

