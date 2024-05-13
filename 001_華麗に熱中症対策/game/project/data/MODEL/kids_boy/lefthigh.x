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
 64;
 2.85882;-0.11178;-1.61514;,
 2.85882;-7.76065;-1.61514;,
 2.31449;-7.76065;-2.57526;,
 2.31449;-0.11178;-2.57526;,
 -2.99807;-0.11178;-1.61514;,
 -1.98707;0.24606;-1.61514;,
 -1.98707;-0.11178;-2.90954;,
 -2.62325;-0.11178;-2.57526;,
 -2.99807;-7.76065;-1.61514;,
 -2.62325;-7.76065;-2.57526;,
 -1.98707;-8.19658;-1.61514;,
 -1.98707;-7.76065;-2.90954;,
 -2.62325;-7.76065;2.57526;,
 -1.98707;-7.76065;3.08692;,
 -1.98707;-0.11178;3.08692;,
 -2.62325;-0.11178;2.57526;,
 1.68576;0.24606;-1.61514;,
 1.68576;-0.11178;-2.90954;,
 1.68576;-7.76065;-2.90954;,
 1.68576;-8.19658;-1.61514;,
 1.68576;-7.76065;3.08692;,
 1.68576;-0.11178;3.08692;,
 2.31449;-7.76065;2.57526;,
 2.31449;-0.11178;2.57526;,
 2.85882;-7.76065;1.82903;,
 1.68576;-8.19658;1.82903;,
 -1.98707;-8.19658;1.82903;,
 -2.99807;-7.76065;1.82903;,
 -2.99807;-0.11178;1.82903;,
 -1.98707;0.24606;1.82903;,
 1.68576;0.24606;1.82903;,
 2.85882;-0.11178;1.82903;,
 1.82011;-6.79524;-0.98512;,
 1.82011;-11.23105;-0.98512;,
 1.46981;-11.23105;-1.58734;,
 1.46981;-6.79524;-1.58734;,
 -1.94904;-6.79524;-0.98512;,
 -1.29841;-6.64633;-0.98512;,
 -1.29841;-6.79524;-1.79701;,
 -1.70783;-6.79524;-1.58734;,
 -1.94904;-11.23105;-0.98512;,
 -1.70783;-11.23105;-1.58734;,
 -1.29841;-12.25372;-0.98512;,
 -1.29841;-11.23105;-1.79701;,
 -1.70783;-11.23105;1.64321;,
 -1.29841;-11.23105;1.96414;,
 -1.29841;-6.79524;1.96414;,
 -1.70783;-6.79524;1.64321;,
 1.06520;-6.64633;-0.98512;,
 1.06520;-6.79524;-1.79701;,
 1.06520;-11.23105;-1.79701;,
 1.06520;-12.25372;-0.98512;,
 1.06520;-11.23105;1.96414;,
 1.06520;-6.79524;1.96414;,
 1.46981;-11.23105;1.64321;,
 1.46981;-6.79524;1.64321;,
 1.82011;-11.23105;1.17515;,
 1.06520;-12.25372;1.17515;,
 -1.29841;-12.25372;1.17515;,
 -1.94904;-11.23105;1.17515;,
 -1.94904;-6.79524;1.17515;,
 -1.29841;-6.64633;1.17515;,
 1.06520;-6.64633;1.17515;,
 1.82011;-6.79524;1.17515;;
 
 60;
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
 4;27,28,4,8;,
 4;28,29,5,4;,
 4;29,30,16,5;,
 4;30,31,0,16;,
 4;31,24,1,0;,
 4;20,25,24,22;,
 4;13,26,25,20;,
 4;12,27,26,13;,
 4;15,28,27,12;,
 4;14,29,28,15;,
 4;21,30,29,14;,
 4;23,31,30,21;,
 4;22,24,31,23;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,36,39,41;,
 4;42,40,41,43;,
 4;38,43,41,39;,
 4;44,45,46,47;,
 4;37,48,49,38;,
 4;49,50,43,38;,
 4;51,42,43,50;,
 4;46,45,52,53;,
 4;48,32,35,49;,
 4;34,50,49,35;,
 4;33,51,50,34;,
 4;53,52,54,55;,
 4;56,57,51,33;,
 4;57,58,42,51;,
 4;58,59,40,42;,
 4;59,60,36,40;,
 4;60,61,37,36;,
 4;61,62,48,37;,
 4;62,63,32,48;,
 4;63,56,33,32;,
 4;52,57,56,54;,
 4;45,58,57,52;,
 4;44,59,58,45;,
 4;47,60,59,44;,
 4;46,61,60,47;,
 4;53,62,61,46;,
 4;55,63,62,53;,
 4;54,56,63,55;;
 
 MeshMaterialList {
  1;
  60;
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
  88;
  0.725555;0.000000;0.688165;,
  0.697466;0.000000;-0.716618;,
  -0.777908;0.000000;0.628378;,
  -0.236409;0.951286;-0.197902;,
  -0.745446;0.000000;-0.666566;,
  -0.332231;0.000000;0.943198;,
  -0.119112;0.964922;-0.233963;,
  -0.142090;-0.949231;-0.280660;,
  0.334946;0.000000;0.942237;,
  0.108129;0.964257;-0.241901;,
  0.241912;0.000000;-0.970298;,
  0.966933;0.000000;-0.255030;,
  0.154658;-0.976954;-0.147111;,
  -0.173786;-0.974416;-0.142521;,
  -0.982734;0.000000;-0.185024;,
  -0.286787;0.952807;-0.099559;,
  -0.145157;0.982318;-0.118240;,
  0.128748;0.984123;-0.122173;,
  0.326543;-0.934402;0.142345;,
  0.165855;-0.973681;0.156327;,
  -0.184961;-0.971174;0.150371;,
  -0.362638;-0.922872;0.129617;,
  -0.973039;0.000000;0.230641;,
  -0.154701;0.980006;0.125125;,
  0.138339;0.981787;0.130215;,
  0.273708;0.954321;0.119813;,
  0.705489;-0.178835;0.685787;,
  0.676034;-0.204601;-0.707896;,
  0.716967;0.000000;0.697107;,
  0.689672;0.000000;-0.724122;,
  -0.770667;0.000000;0.637238;,
  -0.157603;0.978266;-0.134745;,
  -0.758458;-0.180011;0.626369;,
  -0.725076;-0.206328;-0.657034;,
  -0.326325;0.000000;0.945258;,
  -0.079068;0.984252;-0.158105;,
  -0.297274;-0.330895;-0.895621;,
  -0.359413;-0.316267;0.877951;,
  0.329041;0.000000;0.944316;,
  0.071671;0.983913;-0.163644;,
  0.283784;-0.329724;-0.900416;,
  0.344603;-0.314291;0.884573;,
  0.896547;-0.323134;-0.302965;,
  0.403902;-0.820564;-0.404398;,
  -0.432857;-0.810066;-0.395508;,
  -0.920406;-0.300475;-0.250137;,
  -0.190887;0.979284;-0.067562;,
  -0.095954;0.992212;-0.079430;,
  0.084726;0.993009;-0.082189;,
  0.965504;0.000000;-0.260387;,
  0.891968;-0.307558;0.331362;,
  0.421246;-0.807832;0.412261;,
  -0.451087;-0.797561;0.400522;,
  -0.919309;-0.284705;0.271688;,
  -0.971829;0.000000;0.235685;,
  -0.102440;0.991153;0.084388;,
  0.091269;0.991935;0.087945;,
  0.181691;0.979929;0.082026;,
  -0.341482;-0.932315;-0.119070;,
  -0.281101;-0.930189;-0.236076;,
  -0.239550;0.000000;-0.970884;,
  0.129117;-0.948292;-0.289950;,
  0.255011;0.960901;-0.107888;,
  0.214928;0.952812;-0.214372;,
  0.304986;-0.943576;-0.129025;,
  0.255972;-0.932265;-0.255655;,
  -0.305175;0.946021;0.109143;,
  0.950763;0.000000;0.309918;,
  0.150729;-0.939320;0.308154;,
  0.297973;-0.912051;0.281736;,
  -0.163689;-0.940966;0.296293;,
  -0.322831;-0.910922;0.256909;,
  -0.137754;0.958995;0.247692;,
  -0.272800;0.937303;0.216896;,
  0.126848;0.957822;0.257852;,
  0.251621;0.938140;0.237866;,
  -0.981912;0.000000;-0.189335;,
  -0.738988;0.000000;-0.673719;,
  -0.234451;0.000000;-0.972128;,
  0.236790;0.000000;-0.971561;,
  0.168743;0.982937;-0.073221;,
  0.142953;0.978901;-0.146003;,
  -0.203657;0.976184;0.074762;,
  0.948843;0.000000;0.315747;,
  -0.091902;0.981493;0.168003;,
  -0.182999;0.971744;0.149077;,
  0.084612;0.980906;0.175110;,
  0.168610;0.972030;0.163488;;
  60;
  4;11,11,1,1;,
  4;15,16,6,3;,
  4;14,14,4,4;,
  4;13,58,59,7;,
  4;60,60,4,4;,
  4;2,5,5,2;,
  4;16,17,9,6;,
  4;10,10,60,60;,
  4;12,13,7,61;,
  4;5,5,8,8;,
  4;17,62,63,9;,
  4;1,10,10,1;,
  4;64,12,61,65;,
  4;8,8,0,0;,
  4;18,19,12,64;,
  4;19,20,13,12;,
  4;20,21,58,13;,
  4;22,22,14,14;,
  4;66,23,16,15;,
  4;23,24,17,16;,
  4;24,25,62,17;,
  4;67,67,11,11;,
  4;68,19,18,69;,
  4;70,20,19,68;,
  4;71,21,20,70;,
  4;2,22,22,2;,
  4;72,23,66,73;,
  4;74,24,23,72;,
  4;75,25,24,74;,
  4;0,67,67,0;,
  4;49,42,27,29;,
  4;46,47,35,31;,
  4;45,76,77,33;,
  4;44,45,33,36;,
  4;78,36,33,77;,
  4;32,37,34,30;,
  4;47,48,39,35;,
  4;79,40,36,78;,
  4;43,44,36,40;,
  4;34,37,41,38;,
  4;48,80,81,39;,
  4;27,40,79,29;,
  4;42,43,40,27;,
  4;38,41,26,28;,
  4;50,51,43,42;,
  4;51,52,44,43;,
  4;52,53,45,44;,
  4;53,54,76,45;,
  4;82,55,47,46;,
  4;55,56,48,47;,
  4;56,57,80,48;,
  4;83,50,42,49;,
  4;41,51,50,26;,
  4;37,52,51,41;,
  4;32,53,52,37;,
  4;30,54,53,32;,
  4;84,55,82,85;,
  4;86,56,55,84;,
  4;87,57,56,86;,
  4;26,50,83,28;;
 }
 MeshTextureCoords {
  64;
  0.611539;0.657227;,
  0.611539;0.771777;,
  0.623290;0.771777;,
  0.623290;0.657227;,
  0.737976;0.657227;,
  0.716151;0.651868;,
  0.716151;0.657227;,
  0.729885;0.657227;,
  0.737976;0.771777;,
  0.729885;0.771777;,
  0.716151;0.778305;,
  0.716151;0.771777;,
  0.729885;0.771777;,
  0.716151;0.771777;,
  0.716151;0.657227;,
  0.729885;0.657227;,
  0.636863;0.651868;,
  0.636863;0.657227;,
  0.636863;0.771777;,
  0.636863;0.778305;,
  0.636863;0.771777;,
  0.636863;0.657227;,
  0.623290;0.771777;,
  0.623290;0.657227;,
  0.611539;0.771777;,
  0.636863;0.778305;,
  0.716151;0.778305;,
  0.737976;0.771777;,
  0.737976;0.657227;,
  0.716151;0.651868;,
  0.636863;0.651868;,
  0.611539;0.657227;,
  0.793373;0.866786;,
  0.793373;0.954682;,
  0.811163;0.954682;,
  0.811163;0.866786;,
  0.793373;0.866786;,
  0.793373;0.863836;,
  0.817357;0.866786;,
  0.811163;0.866786;,
  0.793373;0.954682;,
  0.811163;0.954682;,
  0.793373;0.974947;,
  0.817357;0.954682;,
  0.715727;0.954682;,
  0.706246;0.954682;,
  0.706246;0.866786;,
  0.715727;0.866786;,
  0.793373;0.863836;,
  0.817357;0.866786;,
  0.817357;0.954682;,
  0.793373;0.974947;,
  0.706246;0.954682;,
  0.706246;0.866786;,
  0.715727;0.954682;,
  0.715727;0.866786;,
  0.729554;0.954682;,
  0.729554;0.974947;,
  0.729554;0.974947;,
  0.729554;0.954682;,
  0.729554;0.866786;,
  0.729554;0.863836;,
  0.729554;0.863836;,
  0.729554;0.866786;;
 }
}
