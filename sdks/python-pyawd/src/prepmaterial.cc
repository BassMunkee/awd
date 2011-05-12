/**
 * This file contains reparation functions for all blocks belonging in the 
 * pyawd.material module. 
 *
 * These are invoked by AWDWriter to convert a python object to it's C++/libawd
 * equivalence and add it to the AWD document.
*/

#include "AWDWriter.h"
#include "bcache.h"
#include "util.h"


void
__prepare_material(PyObject *block, AWD *awd, pyawd_bcache *bcache)
{
    char *name;
    int name_len;
    awd_uint8 type;
    PyObject *name_attr;
    PyObject *type_attr;
    PyObject *tex_attr;

    AWDSimpleMaterial *lawd_mat;

    type_attr = PyObject_GetAttrString(block, "type");
    type = (awd_uint8)PyInt_AsLong(type_attr);

    name_attr = PyObject_GetAttrString(block, "name");
    name = PyString_AsString(name_attr);
    name_len = PyString_Size(name_attr);

    lawd_mat = new AWDSimpleMaterial(type, name, name_len);

    tex_attr = PyObject_GetAttrString(block, "texture");
    if (tex_attr != Py_None) {
        AWDTexture *tex;
        tex = (AWDTexture *)pyawd_bcache_get(bcache, tex_attr);
        if (tex)
            lawd_mat->set_texture(tex);
    }

    awd->add_material(lawd_mat);
    pyawd_bcache_add(bcache, block, lawd_mat);
}

void
__prepare_texture(PyObject *block, AWD *awd, pyawd_bcache *bcache)
{
    char *name;
    int name_len;
    awd_uint8 type;
    PyObject *url_attr;
    PyObject *type_attr;
    PyObject *name_attr;

    AWDTexture *lawd_tex;

    type_attr = PyObject_GetAttrString(block, "type");
    type = (awd_uint8)PyInt_AsLong(type_attr);

    name_attr = PyObject_GetAttrString(block, "name");
    name = PyString_AsString(name_attr);
    name_len = PyString_Size(name_attr);

    lawd_tex = new AWDTexture(type, name, name_len);

    url_attr = PyObject_GetAttrString(block, "url");
    if (url_attr != Py_None) {
        char *url;
        int url_len;

        url = PyString_AsString(url_attr);
        url_len = PyString_Size(url_attr);
        lawd_tex->set_url(url, url_len);
    }

    awd->add_texture(lawd_tex);
    pyawd_bcache_add(bcache, block, lawd_tex);
}

