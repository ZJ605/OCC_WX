#include "mgeom_paraboloid.h"

#include <cmath>

MGeom_Paraboloid::MGeom_Paraboloid(wxWindow* parent): m_degu(3), m_degv(3), m_focaldistance(15), m_miny(-30.0), m_maxy(30.0)
, m_minz(-30.0), m_maxz(30.0), m_stepy(1), m_stepz(1), m_vertex(0.0,0.0,0.0)

{
    initDialog(parent);
    showDialog();
}

MGeom_Paraboloid::~MGeom_Paraboloid()
{
    //delete m_dialog;
}

TopoDS_Shape MGeom_Paraboloid::getShape()
{
    //TopoDS_Shape s;
    //return s;

    //return m_face;
    return BRepBuilderAPI_MakeFace(m_surf, 0.01).Face();
}

bool MGeom_Paraboloid::calculate()
{
    double county = int((m_maxy - m_miny)/m_stepy) + 1;
    double countz = int((m_maxz - m_minz)/m_stepz) + 1;
    m_points = TColgp_Array2OfPnt(0,county-1,0,countz-1);
    double multiplicator = 1.0/(4.0*m_focaldistance);
    std::cout << "county " << county << " countz " << countz << std::endl;
    for (int i = 0; i < county; i++) {
        for (int j = 0; j < countz; j++)
        {
            double y = m_miny + i*m_stepy;
            double z = m_minz + j*m_stepz;
            double x = multiplicator*((y-m_vertex.Y())*(y-m_vertex.Y()) + (z-m_vertex.Z())*(z-m_vertex.Z())) + m_vertex.X();
            m_points.SetValue(i,j,gp_Pnt(x,y,z));

        }
    }

    int numuknots = county - m_degu;
    int numvknots = countz - m_degv;
    double knotsustep = 1.0/numuknots;
    double knotsvstep = 1.0/numvknots;
    if (numuknots < 1 || numvknots < 1) return false;

    m_knotsu = TColStd_Array1OfReal(0,numuknots);
    m_knotsv = TColStd_Array1OfReal(0,numvknots);
    m_multu = TColStd_Array1OfInteger(0,numuknots);
    m_multv = TColStd_Array1OfInteger(0,numvknots);

    m_knotsu.SetValue(0,0);
    m_multu.SetValue(0,m_degu+1);
    for (int i = 1; i < numuknots; i++)
    {
        m_knotsu.SetValue(i,i*knotsustep);
        m_multu.SetValue(i,1);
    }
    m_knotsu.SetValue(numuknots,1);
    m_multu.SetValue(numuknots,m_degu+1);

    m_knotsv.SetValue(0,0);
    m_multv.SetValue(0,m_degv+1);
    for (int i = 1; i < numvknots; i++)
    {
        m_knotsv.SetValue(i,i*knotsvstep);
        m_multv.SetValue(i,1);
    }
    m_knotsv.SetValue(numvknots,1);
    m_multv.SetValue(numvknots,m_degv+1);

    m_surf = new Geom_BSplineSurface(m_points, m_knotsu, m_knotsv, m_multu, m_multv, m_degu, m_degv, false, false);

    gp_Pnt p = gp_Pnt(0.0,0.0,0.0);
    m_surf->D0(0.1,0.1,p);
    m_face = BRepBuilderAPI_MakeFace(m_surf, 0.01).Face();

    return true;
}

void MGeom_Paraboloid::showDialog()
{
    m_dialog->Show();
}

void MGeom_Paraboloid::onUpdateDialog(const wxCommandEvent& ev)
{
    std::cout << "updated in " << std::endl;
}

void MGeom_Paraboloid::initDialog(wxWindow* parent)
{
    m_dialog = new MGeom_ParabolaDialog(parent, this, &MGeom_Paraboloid::onUpdateDialog);
    showDialog();
}
