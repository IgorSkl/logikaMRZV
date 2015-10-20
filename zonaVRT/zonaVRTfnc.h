

short isNewZonaMethodVRT( int numclon);
short isZonaTrianMethodVRT(int numclon);

char controlPoint1VRT();
char controlPoint2VRT();
char controlPoint3VRT();
char controlPoint4VRT();
double makeNormalVectorVRT(double xOpor, double yOpor, 
                           double xVect, double yVect, VectorXY_VRT *nVector);
double makeUgolVectorVRT(VectorXY_VRT *nVector);
double splitUgolSVRT(double ugolS, int *raz);//& raz);
void makeVozvPointVRT(int lineID, double tmpShift, int cntRaz);
void makeLineVVRT(double x0, double y0, double x1, double y1, LineXY_VRT *lineV);
VectorXY_VRT makeVozvCrossPointVRT(VectorXY_VRT *vector1, VectorXY_VRT *vector2, 
                                   LineXY_VRT *lineV1, LineXY_VRT *lineV2);
double makeXPVRT(double K1, double K2, double B1, double B2);
double makeLenVectorVRT(double xn, double yn);
double makeKoefKVRT(double X0, double Y0, double X1, double Y1);
double makeKoefBVRT(double X0, double Y0, double X1, double Y1);

char controlPoint3TrianVRT();
int isViewZMethod_64VRT(int numclon, int idxIsZona);
int isViewZTrianMethod_64VRT(int numClon, int idxIsZona);
int isSectorZ_64VRT(VectorXY_64 *oporZ, VectorXY_64 *nVectorLow, VectorXY_64 *nVectorHi);
void makeOporVectorZ_64VRT(INT_64 xOpor_64, INT_64 yOpor_64, VectorXY_64 *oporZ_64);
INT_64 makeLenVector_64VRT(VectorXY_64 *oporZ_64);


