#ifndef MAIS_SHAPE_H
#define MAIS_SHAPE_H

#include "AIS_Shape.hxx"
#include "Prs3d_Drawer.hxx"
#include "Prs3d_LineAspect.hxx"
#include "Prs3d_Presentation.hxx"
#include "PrsMgr_PresentationManager3d.hxx"
#include "Prs3d.hxx"
#include "mgeom.h"

class MAIS_Shape : public AIS_Shape
{
    DEFINE_STANDARD_RTTI_INLINE(MAIS_Shape, AIS_Shape)

    public:
        MAIS_Shape(Handle(MGeom) mgeom);

        virtual void Compute(const Handle(PrsMgr_PresentationManager3d)& prsmgr, const Handle(Prs3d_Presentation)& prs, const Standard_Integer mode) override;
        virtual void ComputeSelection(const Handle(SelectMgr_Selection)& sel, const Standard_Integer mode) override;
        virtual bool AcceptDisplayMode(){return true;}

        const char* getMGeomType();
        Handle(MGeom) getMGeomHandle(){return m_mgeom;}
    private:

        Handle(MGeom) m_mgeom;
};

#endif // MAIS_SHAPE_H
