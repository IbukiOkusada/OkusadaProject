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
 34;
 3.87434;-0.56650;-2.54079;,
 3.87434;-1.95519;-2.54079;,
 3.87434;-2.50748;-7.11348;,
 3.87434;-0.99391;-4.90331;,
 -3.05353;-0.19017;-4.90331;,
 -3.05353;0.29275;-2.54079;,
 3.10615;0.29275;-2.54079;,
 3.10615;-0.19017;-4.90331;,
 -3.87434;-2.34679;-7.11348;,
 -3.87434;-1.79450;-2.54079;,
 -3.87434;-0.49649;-2.54079;,
 -3.87434;-0.83321;-4.90331;,
 3.10615;-3.89639;-8.55182;,
 3.10615;-3.89639;-2.54079;,
 -3.05353;-3.89639;-2.54079;,
 -3.05353;-3.89639;-8.55182;,
 3.10615;-1.36815;-7.11348;,
 -3.05353;-1.36815;-7.11348;,
 -3.05353;0.29275;3.68156;,
 -3.05353;-1.52409;4.15512;,
 3.10615;-1.52409;4.15512;,
 3.10615;0.29275;3.68156;,
 -3.05353;-3.89639;4.15512;,
 3.10615;-3.89639;4.15512;,
 -3.87434;-0.49649;3.68156;,
 -3.87434;-1.79450;3.68156;,
 3.87434;-1.95519;3.68156;,
 3.87434;-0.56650;3.68156;,
 3.87434;-3.89639;3.68156;,
 3.87434;-3.89639;-2.54079;,
 3.87434;-3.89639;-8.18120;,
 -3.87434;-3.89639;-2.54079;,
 -3.87434;-3.89639;-8.18120;,
 -3.87434;-3.89639;3.68156;;
 
 32;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;7,16,17,4;,
 4;18,19,20,21;,
 4;22,14,13,23;,
 4;24,10,9,25;,
 4;21,6,5,18;,
 4;26,1,0,27;,
 4;28,29,1,26;,
 4;2,1,29,30;,
 4;16,12,15,17;,
 4;31,9,8,32;,
 4;25,9,31,33;,
 4;19,22,23,20;,
 4;27,0,6,21;,
 4;7,6,0,3;,
 4;2,16,7,3;,
 4;30,12,16,2;,
 4;29,13,12,30;,
 4;23,13,29,28;,
 4;20,23,28,26;,
 4;21,20,26,27;,
 4;33,31,14,22;,
 4;15,14,31,32;,
 4;17,15,32,8;,
 4;4,17,8,11;,
 4;10,5,4,11;,
 4;18,5,10,24;,
 4;25,19,18,24;,
 4;33,22,19,25;;
 
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
    "data\\TEXTURE\\UV\\society_UV.png";
   }
  }
 }
 MeshNormals {
  35;
  0.873145;0.000000;0.487461;,
  1.000000;0.000000;0.000000;,
  0.934212;0.356717;0.000000;,
  0.876506;0.449600;-0.172036;,
  -0.920084;0.391722;0.000000;,
  -0.835699;0.514559;-0.191926;,
  -1.000000;0.000000;0.000000;,
  -0.914893;0.402154;-0.035250;,
  0.932458;0.359602;-0.034772;,
  0.856985;0.036095;0.514076;,
  0.903087;0.302989;-0.304353;,
  -0.959931;0.240201;-0.144348;,
  0.207201;0.192285;0.959215;,
  0.404098;0.910234;-0.090438;,
  0.400955;0.859395;-0.317295;,
  0.330801;0.671744;-0.662820;,
  0.000000;-1.000000;-0.000000;,
  0.240960;0.097371;0.965638;,
  -0.288234;0.679540;-0.674646;,
  -0.346878;0.880868;-0.322099;,
  -0.361466;0.928171;-0.088552;,
  -0.190869;0.192305;0.962594;,
  -0.225702;0.097352;0.969320;,
  0.408351;0.912825;0.000000;,
  -0.373609;0.927587;0.000000;,
  0.247590;0.507981;-0.825018;,
  -0.220577;0.500240;-0.837321;,
  -0.258671;0.000000;0.965965;,
  0.272719;0.000000;0.962094;,
  0.479475;0.489252;-0.728517;,
  0.404747;0.123387;0.906066;,
  -0.430191;0.481129;-0.763840;,
  -0.438790;0.062611;0.896406;,
  -0.374095;0.124686;0.918970;,
  -0.499735;0.000000;0.866178;;
  32;
  4;8,1,10,3;,
  4;19,20,13,14;,
  4;11,6,7,5;,
  4;16,16,16,16;,
  4;14,15,18,19;,
  4;21,22,17,12;,
  4;16,16,16,16;,
  4;4,7,6,6;,
  4;23,13,20,24;,
  4;9,1,8,2;,
  4;0,1,1,9;,
  4;10,1,1,1;,
  4;15,25,26,18;,
  4;6,6,11,6;,
  4;6,6,6,6;,
  4;22,27,28,17;,
  4;2,8,13,23;,
  4;14,13,8,3;,
  4;10,15,14,3;,
  4;29,25,15,10;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,28,0,9;,
  4;12,17,9,30;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;18,26,31,31;,
  4;19,18,11,5;,
  4;7,20,19,5;,
  4;24,20,7,4;,
  4;32,22,21,33;,
  4;34,27,22,32;;
 }
 MeshTextureCoords {
  34;
  0.395035;0.635007;,
  0.395035;0.666760;,
  0.395035;0.679388;,
  0.395035;0.644780;,
  0.480674;0.626402;,
  0.480674;0.615360;,
  0.404531;0.615360;,
  0.404531;0.626402;,
  0.490820;0.675714;,
  0.490820;0.663086;,
  0.490820;0.633406;,
  0.490820;0.641106;,
  0.404531;0.711146;,
  0.404531;0.711146;,
  0.480674;0.711146;,
  0.480674;0.711146;,
  0.404531;0.653337;,
  0.480674;0.653337;,
  0.480674;0.615360;,
  0.480674;0.656903;,
  0.404531;0.656903;,
  0.404531;0.615360;,
  0.480674;0.711146;,
  0.404531;0.711146;,
  0.490820;0.633406;,
  0.490820;0.663086;,
  0.395035;0.666760;,
  0.395035;0.635007;,
  0.395035;0.711146;,
  0.395035;0.711146;,
  0.395035;0.711146;,
  0.490820;0.711146;,
  0.490820;0.711146;,
  0.490820;0.711146;;
 }
}
