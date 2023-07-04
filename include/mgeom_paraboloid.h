#ifndef MGEOM_PARABOLOID_H
#define MGEOM_PARABOLOID_H

#include "mgeom.h"
#include "TopoDS.hxx"
#include "Geom_CartesianPoint.hxx"
#include "TColgp_Array2OfPnt.hxx"
#include "TColStd_Array1OfReal.hxx"
#include "TColStd_Array1OfInteger.hxx"
#include "Geom_BSplineSurface.hxx"
#include "TopoDS_Face.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "Geom_CartesianPoint.hxx"
#include "mgeom_paraboladialog.h"

#include <list>

#include "mparser.h"

class MGeom_ParabolaDialog;

//approximated paraboloid from points according equation
class MGeom_Paraboloid : public MGeom
{
    DEFINE_STANDARD_RTTI_INLINE(MGeom_Paraboloid, MGeom)

    public:
        MGeom_Paraboloid(wxWindow* parent);
        virtual ~MGeom_Paraboloid();

        virtual TopoDS_Shape getShape() Standard_OVERRIDE;
        virtual bool calculate() Standard_OVERRIDE;
        virtual char* getMgeomType() Standard_OVERRIDE;

        void initDialog(wxWindow* parent);
        virtual void showDialog() override;
        void onUpdateDialog(const wxCommandEvent&);
        void updateDialog();

    //getters and setters
    public:
        int getDegU(){return m_degu;}
        int getDegV(){return m_degv;}
        double getFocalDistance(){return m_focaldistance;}
        double getMinY(){return m_miny;}
        double getMaxY(){return m_maxy;}
        double getMinZ(){return m_minz;}
        double getMaxZ(){return m_maxz;}
        double getStepY(){return m_stepy;}
        double getStepZ(){return m_stepz;}
        Geom_CartesianPoint getVertex(){return m_vertex;}

        void setDegU(int deg){m_degu = deg;}
        void setDegV(int deg){m_degv = deg;}
        void setFocalDistance(double distance){m_focaldistance = distance;}
        void setMinY(double val){m_miny = val;}
        void setMaxY(double val){ m_maxy = val;}
        void setMinZ(double val){ m_minz = val;}
        void setMaxZ(double val){ m_maxz = val;}
        void setStepY(double val){ m_stepy = val;}
        void setStepZ(double val){ m_stepz = val;}

    private:
        int m_degu;
        int m_degv;
        double m_focaldistance;
        double m_miny;
        double m_maxy;
        double m_minz;
        double m_maxz;
        double m_stepy;
        double m_stepz;
        Geom_CartesianPoint m_vertex;
        //std::list<Geom_CartesianPoint>
        TColgp_Array2OfPnt m_points;

        //not accessible properties
        TColStd_Array1OfReal m_knotsu;
        TColStd_Array1OfReal m_knotsv;
        TColStd_Array1OfInteger m_multu;
        TColStd_Array1OfInteger m_multv;

        Handle(Geom_BSplineSurface) m_surf;
        TopoDS_Face m_face;

        MGeom_ParabolaDialog *m_dialog;

};

#endif // MGEOM_PARABOLOID_H
