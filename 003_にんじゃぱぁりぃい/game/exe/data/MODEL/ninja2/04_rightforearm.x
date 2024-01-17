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
 68;
 -22.48777;-0.13766;-4.60077;,
 -22.48921;-3.31438;-3.28490;,
 -25.72042;-1.72602;-1.72466;,
 -25.71971;-0.13766;-2.38259;,
 -22.50930;3.03908;-3.28507;,
 -25.73048;1.45070;-1.72474;,
 -22.54116;4.35494;-0.10848;,
 -25.74641;2.10864;-0.13643;,
 -22.56474;3.03908;3.06820;,
 -25.75819;1.45070;1.45189;,
 -22.56619;-0.13766;4.38408;,
 -25.75892;-0.13766;2.10984;,
 -22.54465;-3.31438;3.06838;,
 -25.74815;-1.72602;1.45198;,
 -22.51280;-4.63024;-0.10822;,
 -25.73038;-2.36264;-0.13630;,
 -6.83517;-0.07560;-4.46419;,
 -6.83662;-3.25234;-3.14830;,
 -6.85668;3.10114;-3.14847;,
 -6.88856;4.41698;0.02812;,
 -6.91212;3.10114;3.20481;,
 -6.91358;-0.07560;4.52068;,
 -6.89207;-3.25234;3.20498;,
 -6.86019;-4.56818;0.02837;,
 -6.87437;-0.07560;0.02825;,
 -26.27105;-0.13766;-0.14103;,
 5.24117;2.22498;-1.99357;,
 5.26206;0.09760;-2.87465;,
 0.67954;0.08350;-5.92345;,
 0.63772;4.33836;-4.16128;,
 5.26753;-2.02986;-1.99335;,
 0.69056;-4.17136;-4.16083;,
 5.25447;-2.91106;0.13409;,
 0.66438;-5.93380;0.09404;,
 5.23043;-2.02986;2.26145;,
 0.61628;-4.17136;4.34873;,
 5.20957;0.09760;3.14252;,
 0.57453;0.08350;6.11087;,
 5.20402;2.22498;2.26122;,
 0.56349;4.33836;4.34825;,
 5.21713;3.10618;0.13376;,
 0.58967;6.10076;0.09339;,
 -6.79880;-0.00094;-6.19129;,
 -6.84202;4.39712;-4.36981;,
 -6.78741;-4.39904;-4.36933;,
 -6.81448;-6.22082;0.02878;,
 -6.86416;-4.39904;4.42669;,
 -6.90735;-0.00094;6.24817;,
 -6.91878;4.39712;4.42621;,
 -6.89172;6.21884;0.02811;,
 -14.20462;-0.08544;-5.61965;,
 -14.24340;3.86278;-3.98448;,
 -14.19440;-4.03364;-3.98406;,
 -14.21870;-5.66904;-0.03584;,
 -14.26331;-4.03364;3.91220;,
 -14.30208;-0.08544;5.54736;,
 -14.31231;3.86278;3.91177;,
 -14.28801;5.49818;-0.03644;,
 -18.53983;-0.09848;-3.04494;,
 -18.56045;2.00250;-2.17483;,
 -18.53437;-2.19946;-2.17460;,
 -18.54731;-3.06970;-0.07362;,
 -18.57104;-2.19946;2.02727;,
 -18.59171;-0.09848;2.89739;,
 -18.59713;2.00250;2.02705;,
 -18.58418;2.87276;-0.07394;,
 6.04743;0.10004;0.14101;,
 -19.11050;-0.10014;-0.07853;;
 
 80;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;10,8,9,11;,
 4;12,10,11,13;,
 4;14,12,13,15;,
 4;1,14,15,2;,
 4;0,16,17,1;,
 4;4,18,16,0;,
 4;6,19,18,4;,
 4;8,20,19,6;,
 4;10,21,20,8;,
 4;12,22,21,10;,
 4;14,23,22,12;,
 4;1,17,23,14;,
 3;16,24,17;,
 3;18,24,16;,
 3;19,24,18;,
 3;20,24,19;,
 3;21,24,20;,
 3;22,24,21;,
 3;23,24,22;,
 3;17,24,23;,
 3;9,7,25;,
 3;11,9,25;,
 3;13,11,25;,
 3;15,13,25;,
 3;2,15,25;,
 3;3,2,25;,
 3;5,3,25;,
 3;7,5,25;,
 4;26,27,28,29;,
 4;27,30,31,28;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,26,29,41;,
 4;29,28,42,43;,
 4;28,31,44,42;,
 4;31,33,45,44;,
 4;33,35,46,45;,
 4;35,37,47,46;,
 4;37,39,48,47;,
 4;39,41,49,48;,
 4;41,29,43,49;,
 4;43,42,50,51;,
 4;42,44,52,50;,
 4;44,45,53,52;,
 4;45,46,54,53;,
 4;46,47,55,54;,
 4;47,48,56,55;,
 4;48,49,57,56;,
 4;49,43,51,57;,
 4;51,50,58,59;,
 4;50,52,60,58;,
 4;52,53,61,60;,
 4;53,54,62,61;,
 4;54,55,63,62;,
 4;55,56,64,63;,
 4;56,57,65,64;,
 4;57,51,59,65;,
 3;27,26,66;,
 3;30,27,66;,
 3;32,30,66;,
 3;34,32,66;,
 3;36,34,66;,
 3;38,36,66;,
 3;40,38,66;,
 3;26,40,66;,
 3;59,58,67;,
 3;58,60,67;,
 3;60,61,67;,
 3;61,62,67;,
 3;62,63,67;,
 3;63,64,67;,
 3;64,65,67;,
 3;65,59,67;;
 
 MeshMaterialList {
  1;
  80;
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
    "data\\TEXTURE\\UV\\ninja_red.jpg";
   }
  }
 }
 MeshNormals {
  76;
  -0.297593;-0.674981;-0.675159;,
  -0.295772;-0.000863;-0.955258;,
  -0.299862;0.672810;-0.676320;,
  -0.306426;0.951891;-0.002674;,
  -0.311620;0.672810;0.670984;,
  -0.312398;-0.000863;0.949951;,
  -0.309330;-0.674981;0.669862;,
  -0.303175;-0.952931;-0.002646;,
  0.008973;-0.707100;-0.707056;,
  0.008726;-0.000000;-0.999962;,
  0.003368;0.707100;-0.707106;,
  -0.003964;0.999992;-0.000036;,
  -0.008974;0.707100;0.707057;,
  -0.008727;-0.000001;0.999962;,
  -0.003368;-0.707100;0.707105;,
  0.003964;-0.999992;0.000035;,
  -0.999955;-0.003819;-0.008727;,
  0.999957;0.003157;0.008727;,
  -0.833728;0.552127;-0.007273;,
  -0.836812;0.389510;0.384744;,
  -0.837412;-0.002520;0.546566;,
  -0.835847;-0.394622;0.381620;,
  -0.831056;-0.556142;-0.007254;,
  -0.829058;-0.394622;-0.396151;,
  -0.827746;-0.002523;-0.561098;,
  -0.829971;0.389509;-0.399288;,
  0.816353;0.414372;-0.402322;,
  0.819906;0.004938;-0.572477;,
  0.820497;-0.405314;-0.403118;,
  0.817780;-0.575487;0.007132;,
  0.813340;-0.405315;0.417371;,
  0.809793;0.004945;0.586695;,
  0.809206;0.414376;0.416506;,
  0.811924;0.583720;0.007088;,
  0.301874;0.676303;-0.671927;,
  0.309419;0.001784;-0.950924;,
  0.312083;-0.672236;-0.671344;,
  0.308314;-0.951281;0.002690;,
  0.300318;-0.672237;0.676688;,
  0.292776;0.001785;0.956180;,
  0.290103;0.676303;0.677093;,
  0.293871;0.955842;0.002564;,
  -0.031192;0.706493;-0.707032;,
  -0.020628;-0.000204;-0.999787;,
  -0.015171;-0.707027;-0.707024;,
  -0.018021;-0.999838;-0.000157;,
  -0.027508;-0.707027;0.706651;,
  -0.038073;-0.000203;0.999275;,
  -0.043526;0.706493;0.706380;,
  -0.040676;0.999172;-0.000355;,
  -0.311377;0.669631;-0.674269;,
  -0.303869;-0.001875;-0.952712;,
  -0.301213;-0.673867;-0.674666;,
  -0.304971;-0.952358;-0.002661;,
  -0.312941;-0.673868;0.669306;,
  -0.320450;-0.001875;0.947264;,
  -0.323096;0.669632;0.668731;,
  -0.319337;0.947637;-0.002787;,
  -0.828846;0.389414;-0.401710;,
  -0.825430;-0.005045;-0.564482;,
  -0.824864;-0.398663;-0.400833;,
  -0.827474;-0.561457;-0.007221;,
  -0.831733;-0.398666;0.386374;,
  -0.835158;-0.005047;0.549988;,
  -0.835732;0.389415;0.387180;,
  -0.833117;0.553048;-0.007273;,
  0.999943;0.006081;0.008723;,
  -0.999943;-0.006146;-0.008729;,
  0.999957;0.003158;0.008726;,
  0.999957;0.003158;0.008727;,
  0.999957;0.003156;0.008727;,
  0.999957;0.003157;0.008726;,
  0.999957;0.003156;0.008726;,
  0.999957;0.003156;0.008728;,
  0.999957;0.003158;0.008727;,
  0.999957;0.003157;0.008728;;
  80;
  4;1,0,23,24;,
  4;2,1,24,25;,
  4;3,2,25,18;,
  4;4,3,18,19;,
  4;5,4,19,20;,
  4;6,5,20,21;,
  4;7,6,21,22;,
  4;0,7,22,23;,
  4;1,9,8,0;,
  4;2,10,9,1;,
  4;3,11,10,2;,
  4;4,12,11,3;,
  4;5,13,12,4;,
  4;6,14,13,5;,
  4;7,15,14,6;,
  4;0,8,15,7;,
  3;68,17,69;,
  3;70,17,68;,
  3;71,17,70;,
  3;72,17,71;,
  3;73,17,72;,
  3;74,17,73;,
  3;75,17,74;,
  3;69,17,75;,
  3;19,18,16;,
  3;20,19,16;,
  3;21,20,16;,
  3;22,21,16;,
  3;23,22,16;,
  3;24,23,16;,
  3;25,24,16;,
  3;18,25,16;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,33,41,40;,
  4;33,26,34,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,41,49,48;,
  4;41,34,42,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  4;49,42,50,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,55,63,62;,
  4;55,56,64,63;,
  4;56,57,65,64;,
  4;57,50,58,65;,
  3;27,26,66;,
  3;28,27,66;,
  3;29,28,66;,
  3;30,29,66;,
  3;31,30,66;,
  3;32,31,66;,
  3;33,32,66;,
  3;26,33,66;,
  3;58,59,67;,
  3;59,60,67;,
  3;60,61,67;,
  3;61,62,67;,
  3;62,63,67;,
  3;63,64,67;,
  3;64,65,67;,
  3;65,58,67;;
 }
 MeshTextureCoords {
  68;
  0.276792;0.071144;,
  0.276851;0.090102;,
  0.257774;0.080623;,
  0.257744;0.071144;,
  0.276732;0.052185;,
  0.257714;0.061665;,
  0.276707;0.044332;,
  0.257702;0.057738;,
  0.276732;0.052185;,
  0.257714;0.061665;,
  0.276792;0.071144;,
  0.257744;0.071144;,
  0.276851;0.090102;,
  0.257774;0.080623;,
  0.276876;0.097955;,
  0.257797;0.084422;,
  0.393346;0.070773;,
  0.393405;0.089732;,
  0.393286;0.051815;,
  0.393262;0.043962;,
  0.393286;0.051815;,
  0.393346;0.070773;,
  0.393405;0.089732;,
  0.393430;0.097585;,
  0.393346;0.070773;,
  0.254591;0.071144;,
  0.186906;0.312211;,
  0.186984;0.324907;,
  0.159657;0.324991;,
  0.159500;0.299598;,
  0.187063;0.337603;,
  0.159813;0.350383;,
  0.187095;0.342862;,
  0.159878;0.360901;,
  0.187063;0.337603;,
  0.159813;0.350383;,
  0.186984;0.324907;,
  0.159657;0.324991;,
  0.186906;0.312211;,
  0.159500;0.299598;,
  0.186874;0.306952;,
  0.159435;0.289080;,
  0.115304;0.325495;,
  0.115142;0.299247;,
  0.115465;0.351742;,
  0.115532;0.362614;,
  0.115465;0.351742;,
  0.115304;0.325495;,
  0.115142;0.299247;,
  0.115075;0.288375;,
  0.071424;0.325999;,
  0.071279;0.302436;,
  0.071569;0.349561;,
  0.071629;0.359321;,
  0.071569;0.349561;,
  0.071424;0.325999;,
  0.071279;0.302436;,
  0.071218;0.292676;,
  0.045853;0.326077;,
  0.045776;0.313538;,
  0.045931;0.338615;,
  0.045963;0.343809;,
  0.045931;0.338615;,
  0.045853;0.326077;,
  0.045776;0.313538;,
  0.045744;0.308345;,
  0.191797;0.324892;,
  0.042623;0.326087;;
 }
}
