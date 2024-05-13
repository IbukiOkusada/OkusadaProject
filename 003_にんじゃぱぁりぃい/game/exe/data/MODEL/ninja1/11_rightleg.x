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
 26;
 -3.50922;-3.35668;7.01014;,
 0.00000;-3.35668;8.46370;,
 0.00000;-2.03650;8.46370;,
 -3.50922;-2.03650;7.01014;,
 3.50922;-3.35668;7.01014;,
 3.50922;-2.03650;7.01014;,
 4.96278;-3.35668;3.50092;,
 4.96278;-2.03650;3.50092;,
 3.50922;-3.35668;-6.87328;,
 3.50922;-2.03650;-6.87328;,
 0.00000;-3.35668;-8.46370;,
 0.00000;-2.03650;-8.46370;,
 -3.50922;-3.35668;-6.87328;,
 -3.50922;-2.03650;-6.87328;,
 -4.96278;-3.35668;3.50092;,
 -4.96278;-2.03650;3.50092;,
 0.00000;0.33232;8.46370;,
 -3.50922;0.33232;7.01014;,
 3.50922;0.33232;7.01014;,
 4.96278;0.33232;3.50092;,
 3.50922;0.33232;-0.00828;,
 0.00000;0.33232;-1.46186;,
 -3.50922;0.33232;-0.00828;,
 -4.96278;0.33232;3.50092;,
 0.00000;-3.35668;3.50092;,
 0.00000;-0.71630;3.50092;;
 
 32;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 4;3,2,16,17;,
 4;2,5,18,16;,
 4;5,7,19,18;,
 4;7,9,20,19;,
 4;9,11,21,20;,
 4;11,13,22,21;,
 4;13,15,23,22;,
 4;15,3,17,23;,
 3;1,0,24;,
 3;4,1,24;,
 3;6,4,24;,
 3;8,6,24;,
 3;10,8,24;,
 3;12,10,24;,
 3;14,12,24;,
 3;0,14,24;,
 3;17,16,25;,
 3;16,18,25;,
 3;18,19,25;,
 3;19,20,25;,
 3;20,21,25;,
 3;21,22,25;,
 3;22,23,25;,
 3;23,17,25;;
 
 MeshMaterialList {
  1;
  32;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\UV\\ninja_blue.jpg";
   }
  }
 }
 MeshNormals {
  29;
  -0.707107;0.000000;0.707107;,
  0.000000;0.000000;1.000000;,
  0.707107;0.000000;0.707107;,
  0.991979;0.000000;0.126406;,
  0.800756;0.000000;-0.598991;,
  0.000000;0.000000;-1.000000;,
  -0.800756;0.000000;-0.598991;,
  -0.991979;0.000000;0.126406;,
  0.994141;0.050310;0.095668;,
  0.870826;0.070992;-0.486438;,
  -0.870826;0.070992;-0.486438;,
  -0.994141;0.050310;0.095668;,
  0.992768;0.101679;0.063826;,
  0.945746;0.191486;-0.262482;,
  0.000000;0.998220;-0.059635;,
  0.052745;0.998558;-0.009998;,
  -0.992768;0.101679;0.063826;,
  0.000000;-1.000000;-0.000000;,
  -0.000000;1.000000;0.000000;,
  0.138816;0.937124;-0.320201;,
  0.000000;0.946286;-0.323331;,
  -0.052745;0.998558;-0.009998;,
  -0.138816;0.937124;-0.320201;,
  -0.945746;0.191486;-0.262482;,
  0.146182;0.978398;-0.146182;,
  0.000000;0.978398;-0.206732;,
  -0.146182;0.978398;-0.146182;,
  -0.206732;0.978398;0.000000;,
  0.206732;0.978398;0.000000;;
  32;
  4;0,1,1,0;,
  4;1,2,2,1;,
  4;2,3,8,2;,
  4;3,4,9,8;,
  4;4,5,5,9;,
  4;5,6,10,5;,
  4;6,7,11,10;,
  4;7,0,0,11;,
  4;0,1,1,0;,
  4;1,2,2,1;,
  4;2,8,12,2;,
  4;8,9,13,12;,
  4;19,20,14,21;,
  4;20,22,15,14;,
  4;10,11,16,23;,
  4;11,0,0,16;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;24,25,18;,
  3;25,26,18;,
  3;26,27,18;,
  3;27,21,18;,
  3;21,14,18;,
  3;14,15,18;,
  3;15,28,18;,
  3;28,24,18;;
 }
 MeshTextureCoords {
  26;
  0.301483;0.549243;,
  0.280676;0.549243;,
  0.280676;0.541364;,
  0.301483;0.541364;,
  0.259869;0.549243;,
  0.259869;0.541364;,
  0.251251;0.549243;,
  0.251251;0.541364;,
  0.259869;0.549243;,
  0.259869;0.541364;,
  0.280676;0.549243;,
  0.280676;0.541364;,
  0.301483;0.549243;,
  0.301483;0.541364;,
  0.310102;0.549243;,
  0.310102;0.541364;,
  0.280676;0.527227;,
  0.301483;0.527227;,
  0.259869;0.527227;,
  0.251251;0.527227;,
  0.259869;0.527227;,
  0.280676;0.527227;,
  0.301483;0.527227;,
  0.310102;0.527227;,
  0.280676;0.549243;,
  0.280676;0.533486;;
 }
}
