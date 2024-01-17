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
 32;
 -7.94008;1.05636;-1.05030;,
 -8.88883;0.40945;-1.05030;,
 -8.88883;0.40945;1.11326;,
 -7.94008;1.05636;1.11326;,
 0.48398;1.05636;-1.05030;,
 0.48398;1.05636;1.11326;,
 0.82212;0.40945;1.11326;,
 0.82212;0.40945;-1.05030;,
 -7.94008;-2.25498;-1.05030;,
 0.48398;-2.25498;-1.05030;,
 0.48398;-2.25498;1.11326;,
 -7.94008;-2.25498;1.11326;,
 -7.94008;0.40945;1.74733;,
 0.48398;0.40945;1.74733;,
 0.48398;0.77392;1.49528;,
 -7.94008;0.77392;1.49528;,
 0.48398;0.40945;-1.67431;,
 -7.94008;0.40945;-1.67431;,
 -7.94008;0.77392;-1.34923;,
 0.48398;0.77392;-1.34923;,
 0.48398;-2.00759;-1.34923;,
 -7.94008;-2.00759;-1.34923;,
 0.48398;-2.00759;1.49528;,
 -7.94008;-2.00759;1.49528;,
 -7.94008;-1.70308;-1.67431;,
 -8.88883;-1.70308;-1.05030;,
 -8.88883;-1.70308;1.11326;,
 -7.94008;-1.70308;1.74733;,
 0.48398;-1.70308;1.74733;,
 0.82212;-1.70308;1.11326;,
 0.82212;-1.70308;-1.05030;,
 0.48398;-1.70308;-1.67431;;
 
 30;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,7,4,5;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,9,8,21;,
 4;19,4,7,16;,
 4;18,0,4,19;,
 4;17,1,0,18;,
 4;3,2,12,15;,
 4;5,3,15,14;,
 4;13,6,5,14;,
 4;11,10,22,23;,
 4;24,25,1,17;,
 4;2,1,25,26;,
 4;12,2,26,27;,
 4;27,28,13,12;,
 4;28,29,6,13;,
 4;29,30,7,6;,
 4;16,7,30,31;,
 4;31,24,17,16;,
 4;21,8,25,24;,
 4;26,25,8,11;,
 4;27,26,11,23;,
 4;23,22,28,27;,
 4;10,29,28,22;,
 4;9,30,29,10;,
 4;31,30,9,20;,
 4;20,21,24,31;;
 
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
    "data\\TEXTURE\\UV\\kids_girl_UV.png";
   }
  }
 }
 MeshNormals {
  38;
  -0.139351;-0.743139;-0.654466;,
  -0.155800;-0.738194;0.656351;,
  -0.151159;0.688870;-0.708949;,
  -0.168374;0.685920;0.707929;,
  0.299432;0.664891;-0.684296;,
  0.317813;0.659788;0.680936;,
  0.286380;-0.719032;-0.633229;,
  0.305327;-0.711857;0.632483;,
  -0.249375;-0.907133;-0.339000;,
  0.302251;-0.863133;-0.404532;,
  0.000000;0.929211;-0.369548;,
  -0.280317;0.885499;-0.370558;,
  -0.259390;-0.915211;0.308393;,
  -0.290197;0.895339;0.337866;,
  0.000000;0.949762;0.312974;,
  0.493921;-0.825440;0.273298;,
  -0.274658;0.357238;-0.892717;,
  -0.776811;0.441087;-0.449452;,
  -0.786479;0.432981;0.440429;,
  -0.286362;0.323450;0.901874;,
  0.518788;0.284031;0.806340;,
  0.948995;0.220400;0.225461;,
  0.944010;0.229939;-0.236587;,
  0.509750;0.323794;-0.797064;,
  -0.269501;-0.397400;-0.877179;,
  -0.758719;-0.477348;-0.443265;,
  -0.787418;-0.261459;0.558223;,
  -0.280472;-0.362909;0.888613;,
  0.000000;-0.338861;0.940837;,
  0.940985;-0.252380;0.225504;,
  0.935416;-0.263160;-0.236101;,
  0.856377;-0.240303;-0.457025;,
  0.868846;0.445983;-0.214956;,
  0.881950;0.427912;0.197623;,
  0.872093;-0.220820;0.436683;,
  0.000000;-0.397717;-0.917508;,
  -0.502826;-0.864388;0.000000;,
  0.852689;-0.522419;-0.000000;;
  30;
  4;11,17,18,13;,
  4;10,11,13,14;,
  4;21,22,32,33;,
  4;8,9,15,12;,
  4;19,20,5,3;,
  4;23,16,2,4;,
  4;6,9,8,0;,
  4;4,32,22,23;,
  4;2,11,10,4;,
  4;16,17,11,2;,
  4;13,18,19,3;,
  4;14,13,3,5;,
  4;20,21,33,5;,
  4;12,15,7,1;,
  4;24,25,17,16;,
  4;18,17,25,26;,
  4;19,18,26,27;,
  4;27,28,20,19;,
  4;34,29,21,20;,
  4;29,30,22,21;,
  4;23,22,30,31;,
  4;35,24,16,23;,
  4;0,8,25,24;,
  4;36,25,8,12;,
  4;27,26,12,1;,
  4;1,7,28,27;,
  4;15,29,34,7;,
  4;37,30,29,15;,
  4;31,30,9,6;,
  4;6,0,24,35;;
 }
 MeshTextureCoords {
  32;
  0.294657;0.550343;,
  0.294657;0.576541;,
  0.209864;0.576541;,
  0.209864;0.550343;,
  0.294657;0.550343;,
  0.209864;0.550343;,
  0.209864;0.576541;,
  0.294657;0.576541;,
  0.294657;0.684442;,
  0.294657;0.684442;,
  0.209864;0.684442;,
  0.209864;0.684442;,
  0.185014;0.576541;,
  0.185014;0.576541;,
  0.194892;0.561781;,
  0.194892;0.561781;,
  0.319113;0.576541;,
  0.319113;0.576541;,
  0.306373;0.561781;,
  0.306373;0.561781;,
  0.306373;0.674424;,
  0.306373;0.674424;,
  0.194892;0.674424;,
  0.194892;0.674424;,
  0.319113;0.662092;,
  0.294657;0.662092;,
  0.209864;0.662092;,
  0.185014;0.662092;,
  0.185014;0.662092;,
  0.209864;0.662092;,
  0.294657;0.662092;,
  0.319113;0.662092;;
 }
}
