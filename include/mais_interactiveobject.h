#ifndef MAIS_INTERACTIVEOBJECT_H
#define MAIS_INTERACTIVEOBJECT_H

#include "AIS_InteractiveObject.hxx"
#include "AIS_Shape.hxx"

class MAIS_InteractiveObject : public AIS_Shape
{
    DEFINE_STANDARD_RTTI_INLINE(MAIS_InteractiveObject, AIS_Shape)

    public:
        virtual void Compute(const Handle(PrsMgr_PresentationManager3d)& prsmgr, const Handle(Prs3d_Presentation)& prs, const Standard_Integer mode) override;
        virtual void ComputeSelection(const Handle(SelectMgr_Selection)& sel, const Standard_Integer mode) override;
        virtual bool AcceptDisplayMode(){return true;}
    private:
};

#endif // MAIS_INTERACTIVEOBJECT_H
