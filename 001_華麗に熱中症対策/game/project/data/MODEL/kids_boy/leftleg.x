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
 52;
 2.81464;-1.94794;-1.82340;,
 2.81464;-2.94454;-1.82340;,
 2.81464;-3.34088;-5.10500;,
 2.81464;-2.25467;-3.51888;,
 -2.15717;-1.67786;-3.51888;,
 -2.15717;-1.33129;-1.82340;,
 2.26334;-1.33129;-1.82340;,
 2.26334;-1.67786;-3.51888;,
 -2.74622;-3.22556;-5.10500;,
 -2.74622;-2.82922;-1.82340;,
 -2.74622;-1.89769;-1.82340;,
 -2.74622;-2.13935;-3.51888;,
 2.26334;-4.33764;-6.13723;,
 2.26334;-4.33764;-1.82340;,
 -2.15717;-4.33764;-1.82340;,
 -2.15717;-4.33764;-6.13723;,
 2.26334;-2.52325;-5.10500;,
 -2.15717;-2.52325;-5.10500;,
 -2.15717;-1.33129;2.64208;,
 -2.15717;-2.63515;2.98194;,
 2.26334;-2.63515;2.98194;,
 2.26334;-1.33129;2.64208;,
 -2.15717;-4.33764;2.98194;,
 2.26334;-4.33764;2.98194;,
 -2.74622;-1.89769;2.64208;,
 -2.74622;-2.82922;2.64208;,
 2.81464;-2.94454;2.64208;,
 2.81464;-1.94794;2.64208;,
 2.81464;-4.33764;2.64208;,
 2.81464;-4.33764;-1.82340;,
 2.81464;-4.33764;-5.87125;,
 -2.74622;-4.33764;-1.82340;,
 -2.74622;-4.33764;-5.87125;,
 -2.74622;-4.33764;2.64208;,
 -1.56432;-2.13955;-1.44516;,
 -2.22644;-2.13955;0.15337;,
 -2.22644;-0.06487;0.15337;,
 -1.56432;-0.06487;-1.44516;,
 -1.56432;-2.13955;1.75189;,
 -1.56432;-0.06487;1.75189;,
 0.03421;-2.13955;2.41403;,
 0.03421;-0.06487;2.41403;,
 1.63273;-2.13955;1.75189;,
 1.63273;-0.06487;1.75189;,
 2.29487;-2.13955;0.15337;,
 2.29487;-0.06487;0.15337;,
 1.63273;-2.13955;-1.44516;,
 1.63273;-0.06487;-1.44516;,
 0.03421;-2.13955;-2.10728;,
 0.03421;-0.06487;-2.10728;,
 0.03421;-2.13955;0.15337;,
 0.03421;-0.06487;0.15337;;
 
 56;
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
 4;33,22,19,25;,
 4;34,35,36,37;,
 4;35,38,39,36;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,34,37,49;,
 3;35,34,50;,
 3;38,35,50;,
 3;40,38,50;,
 3;42,40,50;,
 3;44,42,50;,
 3;46,44,50;,
 3;48,46,50;,
 3;34,48,50;,
 3;37,36,51;,
 3;36,39,51;,
 3;39,41,51;,
 3;41,43,51;,
 3;43,45,51;,
 3;45,47,51;,
 3;47,49,51;,
 3;49,37,51;;
 
 MeshMaterialList {
  1;
  56;
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
    "data\\TEXTURE\\UV\\kids_boy_UV.png";
   }
  }
 }
 MeshNormals {
  44;
  0.873149;0.000000;0.487454;,
  1.000000;0.000000;0.000000;,
  0.934213;0.356716;0.000000;,
  0.876506;0.449600;-0.172038;,
  -0.920084;0.391721;0.000000;,
  -0.835700;0.514558;-0.191928;,
  -1.000000;0.000000;0.000000;,
  -0.914893;0.402154;-0.035250;,
  0.932458;0.359601;-0.034772;,
  0.856989;0.036096;0.514070;,
  0.903087;0.302989;-0.304355;,
  -0.959931;0.240201;-0.144349;,
  0.207208;0.192292;0.959213;,
  0.404099;0.910233;-0.090438;,
  0.400954;0.859394;-0.317297;,
  0.330800;0.671743;-0.662822;,
  0.000000;-1.000000;-0.000000;,
  0.240967;0.097374;0.965636;,
  -0.288233;0.679538;-0.674648;,
  -0.346879;0.880866;-0.322102;,
  -0.361467;0.928170;-0.088552;,
  -0.190875;0.192312;0.962592;,
  -0.225709;0.097356;0.969318;,
  -0.707107;0.000000;-0.707107;,
  -1.000000;0.000000;0.000001;,
  -0.707108;0.000000;0.707105;,
  0.000001;0.000000;1.000000;,
  0.707107;0.000000;0.707107;,
  1.000000;0.000000;0.000001;,
  0.707105;0.000000;-0.707108;,
  0.000001;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.408352;0.912825;0.000000;,
  -0.373609;0.927586;0.000000;,
  0.247591;0.507982;-0.825017;,
  -0.220577;0.500240;-0.837320;,
  -0.258679;0.000000;0.965963;,
  0.272727;0.000000;0.962091;,
  0.479476;0.489251;-0.728517;,
  0.404759;0.123391;0.906060;,
  -0.430191;0.481128;-0.763840;,
  -0.438803;0.062613;0.896399;,
  -0.374106;0.124690;0.918965;,
  -0.499749;0.000000;0.866170;;
  56;
  4;8,1,10,3;,
  4;19,20,13,14;,
  4;11,6,7,5;,
  4;16,16,16,16;,
  4;14,15,18,19;,
  4;21,22,17,12;,
  4;16,16,16,16;,
  4;4,7,6,6;,
  4;32,13,20,33;,
  4;9,1,8,2;,
  4;0,1,1,9;,
  4;10,1,1,1;,
  4;15,34,35,18;,
  4;6,6,11,6;,
  4;6,6,6,6;,
  4;22,36,37,17;,
  4;2,8,13,32;,
  4;14,13,8,3;,
  4;10,15,14,3;,
  4;38,34,15,10;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;17,37,0,9;,
  4;12,17,9,39;,
  4;16,16,16,16;,
  4;16,16,16,16;,
  4;18,35,40,40;,
  4;19,18,11,5;,
  4;7,20,19,5;,
  4;33,20,7,4;,
  4;41,22,21,42;,
  4;43,36,22,41;,
  4;23,24,24,23;,
  4;24,25,25,24;,
  4;25,26,26,25;,
  4;26,27,27,26;,
  4;27,28,28,27;,
  4;28,29,29,28;,
  4;29,30,30,29;,
  4;30,23,23,30;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;16,16,16;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;,
  3;31,31,31;;
 }
 MeshTextureCoords {
  52;
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
  0.490820;0.711146;,
  0.585129;0.757693;,
  0.566190;0.757693;,
  0.566190;0.704126;,
  0.585129;0.704126;,
  0.547251;0.757693;,
  0.547251;0.704126;,
  0.539407;0.757693;,
  0.539407;0.704126;,
  0.547251;0.757693;,
  0.547251;0.704126;,
  0.566190;0.757693;,
  0.566190;0.704126;,
  0.585129;0.757693;,
  0.585129;0.704126;,
  0.592973;0.757693;,
  0.592973;0.704126;,
  0.566190;0.757693;,
  0.566190;0.704126;;
 }
}
