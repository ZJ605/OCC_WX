#ifndef MGEOM_H
#define MGEOM_H

#include "Geom_Line.hxx"
#include "TopoDS.hxx"

class MGeom : public Standard_Transient
{
    DEFINE_STANDARD_RTTI_INLINE(MGeom, Standard_Transient)

    public:
        MGeom();
        virtual ~MGeom();

        virtual TopoDS_Shape getShape() = 0;
        virtual bool calculate() = 0;
    protected:

    private:
};

#endif // MGEOM_H
