


// ISO 12213-2: Pipeline gas compressibility computation according to the method AGA8-92DC

#include <math.h>
#include <stdio.h>






int main(int argc, char *argv[])

{
double A[58] = { 0.153832600,  1.341953000, -2.998583000, -0.048312280,  0.375796500, -1.589575000, -0.053588470,  0.886594630, -0.710237040, -1.471722000,
          1.321850350, -0.786659250,  0.2291290e-8, 0.157672400, -0.436386400, -0.044081590, -0.003433888,  0.032059050,  0.024873550,  0.073322790,
         -0.001600573,  0.642470600, -0.416260100, -0.066899570,  0.279179500, -0.696605100, -0.002860589, -0.008098836,  3.150547000,  0.007224479,
         -0.705752900,  0.534979200, -0.079314910, -1.418465000, -0.599905e-16, 0.105840200,  0.034317290, -0.007022847,  0.024955870,  0.042968180,
          0.746545300, -0.291961300,  7.294616000, -9.936757000, -0.005399808, -0.243256700,  0.049870160,  0.003733797,  1.874951000,  0.002168144,
         -0.658716400,  0.000205518,  0.009776195, -0.020487080,  0.015573220,  0.006862415, -0.001226752,  0.002850908};

int B[58] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,6,6,7,7,8,8,8,9,9};
int C[58] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1};
int K[58] = {0,0,0,0,0,0,0,0,0,0,0,0,3,2,2,2,4,4,0,0,2,2,2,4,4,4,4,0,1,1,2,2,3,3,4,4,4,0,0,2,2,2,4,4,0,2,2,4,4,0,2,0,2,1,2,2,2,2};
int G[58] = {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0};
int Q[58] = {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1};
int F[58] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int S[58] = {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int W[58] = {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

double U[58] = {0.0,0.5,1.0,3.5,-0.5,4.5,0.5,7.5,9.5,6.0,12.0,12.5,-6.0,2.0,3.0,2.0,2.0,11.0,-0.5,0.5,0.0,4.0,6.0,21.0,23.0,22.0,-1.0,-0.5,7.0,
         -1.0,6.0,4.0,1.0,9.0,-13.0,21.0,8.0,-0.5,0.0,2.0,7.0,9.0,22.0,23.0,1.0,9.0,3.0,8.0,23.0,1.5,5.0,-0.5,4.0,7.0,3.0,0.0,1.0,0.0};

double MW[21] = {16.0430,28.0135,44.0100,30.0700,44.0970,18.0153,34.0820,2.0159,28.0100,31.9988,58.1230,58.1230,72.1500,72.1500,86.1770,100.2040,114.2310,128.2580,142.2850,4.0026,39.9480};

double EI[21] = {151.318300, 99.737780,241.960600,244.166700,298.118300,514.015600,296.355000, 26.957940,105.534800,122.766700,324.068900,
          337.638900,365.599900,370.682300,402.636293,427.722630,450.325022,470.840891,489.558373,  2.610111,119.629900};

double KI[21] = {0.4619255,0.4479153,0.4557489,0.5279209,0.5837490,0.3825868,0.4618263,0.3514916,0.4533894,0.4186954,0.6406937,
          0.6341423,0.6738577,0.6798307,0.7175118,0.7525189,0.7849550,0.8152731,0.8437826,0.3589888,0.4216551};

double GI[21] = {0.000000,0.027815,0.189065,0.079300,0.141239,0.332500,0.088500,0.034369,0.038953,0.021000,0.256692,
          0.281835,0.332267,0.366911,0.289731,0.337542,0.383381,0.427354,0.469659,0.000000,0.000000};

double QI[21] = {0.0,0.0,0.69,0.0,0.0,1.06775,0.633276,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

double FI[21] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

double SI[21] = {0.0,0.0,0.0,0.0,0.0,1.5822,0.390,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

double WI[21] = {0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

double EIJ[21][21] = {
  { 1.000000,0.971640,0.960644,1.000000,0.994635,0.708218,0.931484,1.170520,0.990126,1.000000,1.019530,0.989844,1.002350,0.999268,1.107274,0.880880,0.880973,0.881067,0.881161,1.000000,1.000000},
  { 1.000000,1.000000,1.022740,0.970120,0.945939,0.746954,0.902271,1.086320,1.005710,1.021000,0.946914,0.973384,0.959340,0.945520,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,0.925053,0.960237,0.849408,0.955052,1.281790,1.500000,1.000000,0.906849,0.897362,0.726255,0.859764,0.855134,0.831229,0.808310,0.786323,0.765171,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.022560,0.693168,0.946871,1.164460,1.000000,1.000000,1.000000,1.013060,1.000000,1.005320,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.034787,1.000000,1.000000,1.000000,1.004900,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.008692,1.010126,1.011501,1.012821,1.014089,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.100000,1.000000,1.300000,1.300000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  { 1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000}};

double UIJ[21][21] = {
  {1.000000,0.886106,0.963827,1.000000,0.990877,1.000000,0.736833,1.156390,1.000000,1.000000,1.000000,0.992291,1.000000,1.003670,1.302576,1.191904,1.205769,1.219634,1.233498,1.000000,1.000000},
  {1.000000,1.000000,0.835058,0.816431,0.915502,1.000000,0.993476,0.408838,1.000000,1.000000,1.000000,0.993556,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,0.969870,1.000000,1.000000,1.045290,1.000000,0.900000,1.000000,1.000000,1.000000,1.000000,1.000000,1.066638,1.077634,1.088178,1.098291,1.108021,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.065173,1.000000,0.971926,1.616660,1.000000,1.000000,1.250000,1.250000,1.250000,1.250000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.028973,1.033754,1.038338,1.042735,1.046966,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000}};

double KIJ[21][21] = {
  {1.000000,1.003630,0.995933,1.000000,1.007619,1.000000,1.000080,1.023260,1.000000,1.000000,1.000000,0.997596,1.000000,1.002529,0.982962,0.983565,0.982707,0.981849,0.980991,1.000000,1.000000},
  {1.000000,1.000000,0.982361,1.007960,1.000000,1.000000,0.942596,1.032270,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.008510,1.000000,1.000000,1.007790,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,0.910183,0.895362,0.881152,0.867520,0.854406,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,0.986893,1.000000,0.999969,1.020340,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,0.968130,0.962870,0.957828,0.952441,0.948338,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000}};

double GIJ[21][21] = {
  {1.000000,1.000000,0.807653,1.000000,1.000000,1.000000,1.000000,1.957310,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,0.982746,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,0.370296,1.000000,1.673090,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000},
  {1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000}};

double RGAS = 8.31451e-3;

double BI[18];
double CNS[58];
double K1;
double TT,D,Z,BMIX,T,P;
int  i,j,k;   
int   I, J, N;
double    XI[21];
double SUM = 0.0, U1 = 0.0, G1 = 0.0, Q1 = 0.0, F1 = 0.0, E1 = 0.0;
double XIJ, EIJ0, GIJ0, BN;
double X1 = 0.000001, X2 = 40.0;
double X3, Fp, Fp1, Fp2, Fp3;
double TOL = 0.5e-9;

//
// Examples from ISO 12213-2, page 18, produce the following results:
//
//    P      T       1        2        3        4        5        6
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  6.00   -3.15  0.84053  0.83348  0.79380  0.88550  0.82609  0.85380
//  6.00    6.85  0.86199  0.85596  0.82206  0.90144  0.84969  0.87370
//  6.00   16.85  0.88006  0.87484  0.84544  0.91501  0.86944  0.89052
//  6.00   36.85  0.90867  0.90466  0.88183  0.93674  0.90052  0.91723
//  6.00   56.85  0.93011  0.92696  0.90868  0.95318  0.92368  0.93730
// 12.00   -3.15  0.72133  0.71044  0.64145  0.81024  0.69540  0.75074
// 12.00    6.85  0.76025  0.75066  0.68971  0.83782  0.73780  0.78586
// 12.00   16.85  0.79317  0.78475  0.73123  0.86137  0.77369  0.81569
// 12.00   36.85  0.84515  0.83863  0.79697  0.89913  0.83022  0.86311
// 12.00   56.85  0.88383  0.87870  0.84553  0.92766  0.87211  0.89862


// Gas compositions for example calculations
  static double XJ[21] =
   { 0.9650, 0.0030, 0.0060, 0.0180, 0.0045, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0010, 0.0010, 0.0005, 0.0003, 0.0007, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 };
   

// Temperatures for example calculations
  static double t = -3.15;

// Pressures for example calculations
  static double PP = 6.0;  


 
  for (J=0; J<=20; J++) XI[J] = XJ[J];

/*.....Normalize mole fractions */
  for (I=0; I<=20; I++) SUM += XI[I];
  for (I=0; I<=20; I++) XI[I] /= SUM;

/*.....Calculate molecular weight */
  RGAS = 8.31451e-3;

  for (N=0; N<=17; N++) BI[N] = 0.0;

  K1 = 0.0;

  for (I=0; I<21; I++)
   {K1 += XI[I]*pow(KI[I],2.5);                                                     // B.11
    U1 += XI[I]*pow(EI[I],2.5);                                                     // B.6
    G1 += XI[I]*GI[I];                                                              // B.7
    Q1 += XI[I]*QI[I];                                                              // B.8
    F1 += XI[I]*XI[I] * FI[I];                                                      // B.9
    E1 += XI[I]*EI[I];}

  K1 *= K1;                                                                         // B.11
  U1 *= U1;                                                                         // B.6

  /* for I := 1 to 8 do begin */
  /*  for J := I+1 to 19 do begin */
  for (I=0; I<20; I++)
   {for (J=I+1; J<21; J++)
     {XIJ = XI[I] * XI[J];
      if (XIJ != 0)
       {K1 += 2.0*XIJ*(pow(KIJ[I][J],5.0)-1.0)*pow(KI[I]*KI[J],2.5);                // B.11
        U1 += 2.0*XIJ*(pow(UIJ[I][J],5.0)-1.0)*pow(EI[I]*EI[J],2.5);                // B.6 ??? 2*
        G1 += XIJ*(GIJ[I][J]-1.0)*(GI[I]+GI[J]);}}}                                 // B.7

  for (I=0; I<21; I++)
   {for (J=I; J<21; J++)
    {XIJ = XI[I]*XI[J];
     if (XIJ != 0)
      {if (I != J) XIJ=2*XIJ;
       EIJ0 = EIJ[I][J]*sqrt(EI[I]*EI[J]);                                           // B.3
       GIJ0 = GIJ[I][J]*(GI[I]+GI[J])/2.0;                                           // B.4
       for (N=0; N<=17; N++)
        {BN = pow(GIJ0+1.0-G[N],(double)G[N])*                                       // B.2
              pow(QI[I]*QI[J]+1.0-Q[N],(double)Q[N])*
              pow(sqrt(FI[I]*FI[J])+1.0-F[N],(double)F[N])*
              pow(SI[I]*SI[J]+1.0-S[N],(double)S[N])*
              pow(WI[I]*WI[J]+1.0-W[N],(double)W[N]);
         BI[N] += A[N]*XIJ*pow(EIJ0,U[N])*pow(KI[I]*KI[J],1.5)*BN;}}}}               // B.1

  K1 = pow(K1,0.2);                                                                  // B.11
  U1 = pow(U1,0.2);                                                                  // B.6
  for (N=12; N<58; N++)
   CNS[N] = pow(G1+1.0-G[N],(double)G[N])*                                           // B.5
            pow(Q1*Q1+1.0-Q[N],(double)Q[N])*
            pow(F1+1.0-F[N],(double)F[N])*A[N]*pow(U1,U[N]);
 
	TT=t+273.15;
   
	P=PP;
	T=TT;


  
  D = 0.0;
 
  double DR;
  start:
  D=X1;
  DR = D*K1*K1*K1;                                                                  // (2)
  BMIX = 0.0;
  for (N=0; N<18; N++) BMIX += BI[N]/pow(T,U[N]);                                  // B.1
  Z = 1.0 + BMIX * D;                                                             // (1) B.10
  for (N=12; N<18; N++) Z -= DR*CNS[N]/pow(T,U[N]);                                // (1) B.10
  for (N=12; N<58; N++)
    Z += CNS[N]/pow(T,U[N])*(B[N]-C[N]*K[N]*pow(DR,(double)K[N]))*
          pow(DR,(double)B[N])*exp(-C[N]*pow(DR,(double)K[N]));
  Fp1 = D * RGAS * T * Z;

D=X2;
  DR = D*K1*K1*K1;                                                                  // (2)
  BMIX = 0.0;
  for (N=0; N<18; N++) BMIX += BI[N]/pow(T,U[N]);                                  // B.1
  Z = 1.0 + BMIX * D;                                                             // (1) B.10
  for (N=12; N<18; N++) Z -= DR*CNS[N]/pow(T,U[N]);                                // (1) B.10
  for (N=12; N<58; N++)
    Z += CNS[N]/pow(T,U[N])*(B[N]-C[N]*K[N]*pow(DR,(double)K[N]))*
          pow(DR,(double)B[N])*exp(-C[N]*pow(DR,(double)K[N]));
  Fp2 = D * RGAS * T * Z;

  Fp1 -= P;
  Fp2 -= P;
  if (Fp1*Fp2>=0) goto end;//goto end 

//------------------
// BEGIN ITERATING
//------------------
  for (I=1; I<=50; I++)
// Use False Position to get point 3.*/
   {X3 = X1-Fp1*(X2-X1)/(Fp2-Fp1);
  
D=X3;
  DR = D*K1*K1*K1;                                                                  // (2)
  BMIX = 0.0;
  for (N=0; N<18; N++) BMIX += BI[N]/pow(T,U[N]);                                  // B.1
  Z = 1.0 + BMIX * D;                                                             // (1) B.10
  for (N=12; N<18; N++) Z -= DR*CNS[N]/pow(T,U[N]);                                // (1) B.10
  for (N=12; N<58; N++)
    Z += CNS[N]/pow(T,U[N])*(B[N]-C[N]*K[N]*pow(DR,(double)K[N]))*
          pow(DR,(double)B[N])*exp(-C[N]*pow(DR,(double)K[N]));
  Fp3 = D * RGAS * T * Z;
    Fp3 -= P;
// Use points 1, 2, and 3 to estimate the root using Chamber's method (quadratic solution).
    D = X1*Fp2*Fp3/((Fp1-Fp2)*(Fp1-Fp3))+X2*Fp1*Fp3/((Fp2-Fp1)*(Fp2-Fp3))+X3*Fp1*Fp2/((Fp3-Fp1)*(Fp3-Fp2));
    if ((D-X1)*(D-X2)>=0) D=(X1+X2)/2;
   

  DR = D*K1*K1*K1;                                                                  // (2)
  BMIX = 0.0;
  for (N=0; N<18; N++) BMIX += BI[N]/pow(T,U[N]);                                  // B.1
  Z = 1.0 + BMIX * D;                                                             // (1) B.10
  for (N=12; N<18; N++) Z -= DR*CNS[N]/pow(T,U[N]);                                // (1) B.10
  for (N=12; N<58; N++)
    Z += CNS[N]/pow(T,U[N])*(B[N]-C[N]*K[N]*pow(DR,(double)K[N]))*
          pow(DR,(double)B[N])*exp(-C[N]*pow(DR,(double)K[N]));
  Fp = D * RGAS * T * Z;

    Fp -= P;
    if (fabs(Fp)<=TOL) goto end; 
// Discard quadratic solution if false position root is closer.
    if (fabs(Fp3) < fabs(Fp) && Fp*Fp3 > 0)
     {if (Fp3*Fp1>0) {X1=X3; Fp1=Fp3;}
              else {X2=X3; Fp2=Fp3;}}
    else
// Swap in new value from quadratic solution
    {if (Fp*Fp3 < 0) {X1=D; Fp1=Fp; X2=X3; Fp2=Fp3;}
     else if (Fp3*Fp1 > 0) {X1=D; Fp1=Fp;}
                    else {X2=D; Fp2=Fp;}}}
  D = 0.0;
  goto start;
  end:
     printf("%9.5f",Z);
   printf("\n");
 

 getchar();
}
