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
 57;
 -36.29982;1.92380;-35.50457;,
 -36.59586;1.98873;-30.38632;,
 -30.99165;4.35294;-31.83764;,
 -30.26598;1.98873;-36.71620;,
 36.09987;2.02912;37.06654;,
 36.74399;1.98873;30.29377;,
 31.13977;4.35294;31.74509;,
 30.41411;1.98873;36.62364;,
 -30.99165;4.35294;31.74509;,
 -36.59586;1.98873;30.29377;,
 -37.18617;1.92380;36.44047;,
 -30.26598;1.98873;36.62364;,
 31.13977;4.35294;-31.83764;,
 -30.99165;4.35294;-31.83764;,
 -30.99165;4.35294;31.74509;,
 31.13977;4.35294;31.74509;,
 -36.59586;1.98873;-30.38632;,
 -36.59586;1.98873;30.29377;,
 36.74399;1.98873;30.29377;,
 36.74399;1.98873;-30.38632;,
 32.43282;1.95627;-36.19529;,
 -30.26598;1.98873;-36.71620;,
 -36.29982;-1.72459;-35.50457;,
 -36.59586;-1.78951;-30.38632;,
 -30.26598;-1.78951;-36.71620;,
 -36.59586;-1.78951;30.29377;,
 -36.59586;1.98873;30.29377;,
 -36.59586;1.98873;-30.38632;,
 -36.59586;-1.78951;-30.38632;,
 32.43282;1.95627;-36.19529;,
 32.43282;-1.75705;-36.19529;,
 -30.26598;-1.78951;-36.71620;,
 36.74399;-1.78951;30.29377;,
 36.09987;-1.96196;37.06654;,
 30.41411;-1.78951;36.62364;,
 36.74399;-1.78951;-30.38632;,
 36.74399;1.98873;-30.38632;,
 36.74399;-1.78951;30.29377;,
 30.41411;1.98873;36.62364;,
 -30.26598;1.98873;36.62364;,
 -30.26598;-1.78951;36.62364;,
 30.41411;-1.78951;36.62364;,
 -30.99165;-5.10708;31.74509;,
 31.13977;-5.10708;31.74509;,
 -30.99165;-5.10708;-31.83764;,
 31.13977;-5.10708;-31.83764;,
 31.13977;-5.10708;31.74509;,
 -30.99165;-5.10708;31.74509;,
 36.74399;-1.78951;-30.38632;,
 31.13977;-5.10708;-31.83764;,
 -37.30472;-1.72459;36.38090;,
 32.43282;-1.75705;-36.19529;,
 36.56646;-1.77328;-35.34092;,
 32.43282;1.95627;-36.19529;,
 36.56646;1.97250;-35.34092;,
 36.74399;1.98873;-30.38632;,
 36.56646;1.97250;-35.34092;;
 
 35;
 3;0,1,2;,
 3;3,0,2;,
 3;4,5,6;,
 3;7,4,6;,
 3;8,9,10;,
 3;8,10,11;,
 4;12,13,14,15;,
 4;16,17,14,13;,
 4;6,8,11,7;,
 4;18,19,12,15;,
 4;20,21,13,12;,
 4;0,22,23,1;,
 4;22,0,3,24;,
 4;25,26,27,28;,
 4;3,29,30,31;,
 4;32,5,4,33;,
 4;7,34,33,4;,
 4;35,36,5,37;,
 4;38,39,40,41;,
 4;34,40,42,43;,
 4;44,45,46,47;,
 4;44,42,25,23;,
 4;48,32,43,49;,
 4;32,33,34,43;,
 4;25,42,40,50;,
 4;9,25,50,10;,
 4;40,11,10,50;,
 4;23,22,24,44;,
 4;24,51,49,44;,
 3;52,49,51;,
 3;52,48,49;,
 4;53,54,52,51;,
 4;52,54,55,48;,
 3;56,20,12;,
 3;56,12,19;;
 
 MeshMaterialList {
  1;
  35;
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
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.586400;0.047200;0.138400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  48;
  0.155535;0.969793;0.187909;,
  -0.183919;0.963222;-0.195901;,
  0.182695;0.963593;-0.195221;,
  -0.048502;0.890272;-0.452840;,
  0.246502;-0.934538;-0.256662;,
  -0.210008;-0.952050;0.222478;,
  -0.094283;-0.522271;0.847552;,
  -0.019990;0.900881;0.433605;,
  0.833041;-0.539015;0.124520;,
  -0.385686;0.922531;-0.013496;,
  -0.847228;-0.518949;-0.113561;,
  -0.068893;-0.300501;-0.951290;,
  -0.010018;0.899267;0.437286;,
  0.048978;-0.518010;0.853971;,
  0.392171;0.919752;0.016074;,
  0.390552;0.920541;-0.008536;,
  0.198644;-0.952211;0.232022;,
  0.869176;-0.494230;-0.016397;,
  -0.165346;0.970206;0.177090;,
  -0.392428;0.919621;-0.017277;,
  -0.224641;-0.944028;-0.241554;,
  -0.844512;-0.532926;0.052810;,
  0.093103;-0.454344;-0.885948;,
  0.186089;0.952175;0.242351;,
  -0.255968;0.934240;-0.248347;,
  0.046853;0.887070;-0.459250;,
  -0.998331;0.000000;-0.057745;,
  0.995508;0.000000;0.094677;,
  -0.210715;0.953539;0.215318;,
  -0.285582;-0.916578;0.279870;,
  0.202409;0.000000;-0.979301;,
  0.335965;-0.885155;-0.321913;,
  -0.999583;0.000000;-0.028884;,
  -0.196876;0.000000;-0.980428;,
  -0.094789;0.000000;-0.995497;,
  -0.998569;0.008484;-0.052800;,
  0.105864;0.000000;-0.994381;,
  0.998876;0.000000;0.047392;,
  -0.038859;0.000000;0.999245;,
  -0.077660;0.000000;0.996980;,
  0.999840;0.000000;-0.017907;,
  -0.015268;-0.003799;0.999876;,
  0.242569;-0.917224;0.316008;,
  -0.994280;0.016944;-0.105449;,
  -0.030533;-0.007597;0.999505;,
  -0.339115;-0.883248;-0.323842;,
  0.999359;0.000000;-0.035808;,
  0.251064;0.935916;-0.247038;;
  35;
  3;24,19,1;,
  3;3,24,1;,
  3;23,14,0;,
  3;7,23,0;,
  3;18,9,28;,
  3;18,28,12;,
  4;2,1,18,0;,
  4;19,9,18,1;,
  4;0,18,12,7;,
  4;14,15,2,0;,
  4;25,3,1,2;,
  4;26,26,10,32;,
  4;33,33,34,11;,
  4;21,35,32,10;,
  4;34,36,22,11;,
  4;8,37,27,27;,
  4;38,13,39,39;,
  4;17,40,37,8;,
  4;38,41,6,13;,
  4;13,6,5,16;,
  4;20,4,16,5;,
  4;20,5,21,10;,
  4;17,8,16,4;,
  4;8,42,13,16;,
  4;21,5,6,29;,
  4;35,21,43,43;,
  4;6,41,44,44;,
  4;10,45,45,20;,
  4;11,22,4,20;,
  3;31,4,22;,
  3;31,17,4;,
  4;36,30,30,22;,
  4;46,46,40,17;,
  3;47,25,2;,
  3;47,2,15;;
 }
 MeshTextureCoords {
  57;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.785190;0.228420;,
  0.264910;0.228420;,
  0.264910;0.771580;,
  0.785190;0.771580;,
  0.217980;0.240810;,
  0.217980;0.759190;,
  0.832120;0.759190;,
  0.832120;0.240810;,
  0.796020;0.191190;,
  0.270980;0.186740;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.862580;0.180080;;
 }
}
