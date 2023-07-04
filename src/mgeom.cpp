#include "mgeom.h"

int MGeom::mgeom_id = 0;

MGeom::MGeom() : m_ID(MGeom::mgeom_id)
{
        MGeom::mgeom_id++;
}

MGeom::~MGeom()
{
    //dtor
}

