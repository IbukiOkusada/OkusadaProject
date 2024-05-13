xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 40;
 4.02728;0.42639;-2.06506;,
 3.21019;-14.57966;-1.60170;,
 2.63454;-14.57966;-2.59131;,
 3.29976;0.42639;-3.31577;,
 -3.80073;0.42639;-2.06506;,
 -2.44947;2.41979;-2.06506;,
 -2.44947;0.42639;-3.75124;,
 -3.29976;0.42639;-3.31577;,
 -2.98363;-14.57966;-1.60170;,
 -2.58725;-14.57966;-2.59131;,
 -1.91447;-16.38539;-1.60170;,
 -1.91447;-14.57966;-2.93587;,
 -2.58725;-14.57966;2.71741;,
 -1.91447;-14.57966;3.24479;,
 -2.44947;0.42639;4.06015;,
 -3.29976;0.42639;3.39363;,
 2.45944;2.41979;-2.06506;,
 2.45944;0.42639;-3.75124;,
 1.96965;-14.57966;-2.93587;,
 1.96965;-16.38539;-1.60170;,
 1.96965;-14.57966;3.24479;,
 2.45944;0.42639;4.06015;,
 2.63454;-14.57966;2.71741;,
 3.29976;0.42639;3.39363;,
 3.21019;-14.57966;1.94826;,
 1.96965;-16.38539;1.94826;,
 -1.91447;-16.38539;1.94826;,
 -2.98363;-14.57966;1.94826;,
 -2.98363;-14.57966;1.94826;,
 -3.80073;0.42639;2.42154;,
 -3.80073;0.42639;-2.06506;,
 -2.98363;-14.57966;-1.60170;,
 -3.80073;0.42639;2.42154;,
 -2.44947;2.41979;2.42154;,
 2.45944;2.41979;2.42154;,
 4.02728;0.42639;2.42154;,
 4.02728;0.42639;2.42154;,
 3.21019;-14.57966;1.94826;,
 3.21019;-14.57966;-1.60170;,
 4.02728;0.42639;-2.06506;;
 
 30;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,4,7,9;,
 4;10,8,9,11;,
 4;6,11,9,7;,
 4;12,13,14,15;,
 4;5,16,17,6;,
 4;17,18,11,6;,
 4;19,10,11,18;,
 4;14,13,20,21;,
 4;16,0,3,17;,
 4;2,18,17,3;,
 4;1,19,18,2;,
 4;21,20,22,23;,
 4;24,25,19,1;,
 4;25,26,10,19;,
 4;26,27,8,10;,
 4;28,29,30,31;,
 4;32,33,5,4;,
 4;33,34,16,5;,
 4;34,35,0,16;,
 4;36,37,38,39;,
 4;20,25,24,22;,
 4;13,26,25,20;,
 4;12,27,26,13;,
 4;15,32,27,12;,
 4;14,33,32,15;,
 4;21,34,33,14;,
 4;23,35,34,21;,
 4;22,24,35,23;;
 
 MeshMaterialList {
  1;
  30;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\UV\\society_yellow_UV.png";
   }
  }
 }
 MeshNormals {
  33;
  0.700959;-0.210588;0.681402;,
  0.670964;-0.236569;-0.702739;,
  0.709409;0.145629;0.689587;,
  0.680559;0.170881;-0.712488;,
  -0.762863;0.145700;0.629930;,
  -0.730174;0.171772;-0.661317;,
  -0.753362;-0.212820;0.622217;,
  -0.719382;-0.239076;-0.652175;,
  -0.361378;0.301042;0.882485;,
  -0.298390;0.316460;-0.900454;,
  -0.296342;-0.343598;-0.891135;,
  -0.357515;-0.329835;0.873723;,
  0.346504;0.299679;0.888891;,
  0.284812;0.315764;-0.905083;,
  0.282910;-0.341956;-0.896118;,
  0.342746;-0.327256;0.880584;,
  0.892214;-0.335535;-0.302275;,
  0.418297;-0.805622;-0.419525;,
  -0.446948;-0.794880;-0.410369;,
  -0.916101;-0.313243;-0.250278;,
  -0.924939;0.286151;-0.250212;,
  -0.420065;0.823129;-0.382104;,
  0.390898;0.833365;-0.390771;,
  0.901206;0.309052;-0.303834;,
  0.887993;-0.320542;0.329731;,
  0.435514;-0.792679;0.426600;,
  -0.594968;-0.774383;0.215278;,
  -0.915259;-0.298160;0.270928;,
  -0.923550;0.269773;0.272539;,
  -0.438304;0.810852;0.387825;,
  0.408315;0.820883;0.399288;,
  0.896242;0.292966;0.333047;,
  0.000000;-0.583239;0.812301;;
  30;
  4;23,16,1,3;,
  4;20,21,9,5;,
  4;19,20,5,7;,
  4;18,19,7,10;,
  4;9,10,7,5;,
  4;6,11,8,4;,
  4;21,22,13,9;,
  4;13,14,10,9;,
  4;17,18,10,14;,
  4;8,11,15,12;,
  4;22,23,3,13;,
  4;1,14,13,3;,
  4;16,17,14,1;,
  4;12,15,0,2;,
  4;24,25,17,16;,
  4;25,26,18,17;,
  4;26,27,19,18;,
  4;27,28,20,19;,
  4;28,29,21,20;,
  4;29,30,22,21;,
  4;30,31,23,22;,
  4;31,24,16,23;,
  4;15,25,24,0;,
  4;11,32,25,15;,
  4;6,27,26,11;,
  4;4,28,27,6;,
  4;8,29,28,4;,
  4;12,30,29,8;,
  4;2,31,30,12;,
  4;0,24,31,2;;
 }
 MeshTextureCoords {
  40;
  0.847450;0.730012;,
  0.862660;0.846290;,
  0.873375;0.846290;,
  0.860993;0.730012;,
  0.993166;0.730012;,
  0.968013;0.714566;,
  0.968013;0.730012;,
  0.983841;0.730012;,
  0.977956;0.846290;,
  0.970577;0.846290;,
  0.958054;0.860282;,
  0.958054;0.846290;,
  0.970577;0.846290;,
  0.958054;0.846290;,
  0.968013;0.730012;,
  0.983841;0.730012;,
  0.876635;0.714566;,
  0.876635;0.730012;,
  0.885752;0.846290;,
  0.885752;0.860282;,
  0.885752;0.846290;,
  0.876635;0.730012;,
  0.873375;0.846290;,
  0.860993;0.730012;,
  0.862660;0.846290;,
  0.885752;0.860282;,
  0.958054;0.860282;,
  0.977956;0.846290;,
  0.879641;0.978976;,
  0.867792;0.866653;,
  0.980116;0.866653;,
  0.968516;0.978976;,
  0.993166;0.730012;,
  0.968013;0.714566;,
  0.876635;0.714566;,
  0.847450;0.730012;,
  0.867350;0.732173;,
  0.877609;0.844496;,
  0.954559;0.844496;,
  0.964603;0.732173;;
 }
}
