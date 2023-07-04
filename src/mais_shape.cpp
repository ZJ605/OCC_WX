#include "mais_shape.h"

MAIS_Shape::MAIS_Shape(Handle(MGeom) mgeom) : AIS_Shape(mgeom->getShape()), m_mgeom(mgeom)
{
    //ctor
}

void MAIS_Shape::Compute(const Handle(PrsMgr_PresentationManager3d)& prsmgr, const Handle(Prs3d_Presentation)& prs, const Standard_Integer mode)
{
    AIS_Shape::Compute(prsmgr, prs, mode);

     Handle(Prs3d_LineAspect) lineAspect = new Prs3d_LineAspect(Quantity_NOC_RED, Aspect_TOL_SOLID, 2.0);

     Handle(Prs3d_Drawer) drawer = new Prs3d_Drawer();
     drawer->SetLineAspect(new Prs3d_LineAspect(Quantity_NOC_RED, Aspect_TOL_SOLID, 2.0));

     //prs->SetDrawer(drawer);
}

void MAIS_Shape::ComputeSelection(const Handle(SelectMgr_Selection)& sel, const Standard_Integer mode)
{
    AIS_Shape::ComputeSelection(sel,mode);

}

const char* MAIS_Shape::getMGeomType()
{
    return m_mgeom->getMgeomType();
}
