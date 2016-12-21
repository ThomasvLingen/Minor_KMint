//
// Created by mafn on 12/16/16.
//

#include "BeeField.hpp"
#include "../UnusedMacro.hpp"
#include "../RandomUtil.hpp"
#include "../GameObjects/Bee/Bee.hpp"

BeeField::BeeField()
: _bg_image(this->mApplication->LoadTexture("map.png"))
{
    this->_init_field();
    this->SetSize(600, 600);
    this->beekeeper = new BeeKeeper(*this, RANDOM.choice(this->field.get_vertices()));
    this->mApplication->AddRenderable(this);
    this->mApplication->AddRenderable(this->beekeeper);
    for ( int i = 0 ; i < 100; i++){
        this->mApplication->AddRenderable(
            new Bee(
                *this, 0.1,
                {(double)RANDOM.get_random_int(0,this->mWidth), (double)RANDOM.get_random_int(0, this->mHeight)}
            )
        );
    }
}

void BeeField::_init_field()
{
    auto vertex103 = new Vertex(28, 31);
    this->field.add_vertex(vertex103);
    auto vertex104 = new Vertex(60, 49);
    this->field.add_vertex(vertex104);
    auto vertex105 = new Vertex(15, 76);
    this->field.add_vertex(vertex105);
    auto vertex106 = new Vertex(39, 96);
    this->field.add_vertex(vertex106);
    auto vertex107 = new Vertex(141, 97);
    this->field.add_vertex(vertex107);
    auto vertex108 = new Vertex(129, 30);
    this->field.add_vertex(vertex108);
    auto vertex109 = new Vertex(186, 64);
    this->field.add_vertex(vertex109);
    auto vertex110 = new Vertex(201, 15);
    this->field.add_vertex(vertex110);
    auto vertex111 = new Vertex(258, 49);
    this->field.add_vertex(vertex111);
    auto vertex112 = new Vertex(213, 78);
    this->field.add_vertex(vertex112);
    auto vertex113 = new Vertex(241, 94);
    this->field.add_vertex(vertex113);
    auto vertex114 = new Vertex(216, 106);
    this->field.add_vertex(vertex114);
    auto vertex115 = new Vertex(312, 157);
    this->field.add_vertex(vertex115);
    auto vertex116 = new Vertex(289, 172);
    this->field.add_vertex(vertex116);
    auto vertex117 = new Vertex(444, 235);
    this->field.add_vertex(vertex117);
    auto vertex118 = new Vertex(487, 202);
    this->field.add_vertex(vertex118);
    auto vertex119 = new Vertex(457, 186);
    this->field.add_vertex(vertex119);
    auto vertex120 = new Vertex(483, 169);
    this->field.add_vertex(vertex120);
    auto vertex121 = new Vertex(526, 138);
    this->field.add_vertex(vertex121);
    auto vertex122 = new Vertex(556, 156);
    this->field.add_vertex(vertex122);
    auto vertex123 = new Vertex(435, 96);
    this->field.add_vertex(vertex123);
    auto vertex124 = new Vertex(408, 82);
    this->field.add_vertex(vertex124);
    auto vertex125 = new Vertex(488, 61);
    this->field.add_vertex(vertex125);
    auto vertex126 = new Vertex(399, 121);
    this->field.add_vertex(vertex126);
    auto vertex127 = new Vertex(367, 108);
    this->field.add_vertex(vertex127);
    auto vertex128 = new Vertex(346, 122);
    this->field.add_vertex(vertex128);
    auto vertex129 = new Vertex(288, 91);
    this->field.add_vertex(vertex129);
    auto vertex130 = new Vertex(351, 46);
    this->field.add_vertex(vertex130);
    auto vertex131 = new Vertex(301, 15);
    this->field.add_vertex(vertex131);
    auto vertex132 = new Vertex(402, 15);
    this->field.add_vertex(vertex132);
    auto vertex133 = new Vertex(547, 18);
    this->field.add_vertex(vertex133);
    auto vertex134 = new Vertex(531, 33);
    this->field.add_vertex(vertex134);
    auto vertex135 = new Vertex(562, 49);
    this->field.add_vertex(vertex135);
    auto vertex136 = new Vertex(541, 64);
    this->field.add_vertex(vertex136);
    auto vertex137 = new Vertex(567, 79);
    this->field.add_vertex(vertex137);
    auto vertex138 = new Vertex(544, 93);
    this->field.add_vertex(vertex138);
    auto vertex139 = new Vertex(574, 112);
    this->field.add_vertex(vertex139);
    auto vertex140 = new Vertex(568, 220);
    this->field.add_vertex(vertex140);
    auto vertex141 = new Vertex(570, 250);
    this->field.add_vertex(vertex141);
    auto vertex142 = new Vertex(543, 234);
    this->field.add_vertex(vertex142);
    auto vertex143 = new Vertex(499, 264);
    this->field.add_vertex(vertex143);
    auto vertex144 = new Vertex(553, 297);
    this->field.add_vertex(vertex144);
    auto vertex145 = new Vertex(486, 341);
    this->field.add_vertex(vertex145);
    auto vertex146 = new Vertex(430, 310);
    this->field.add_vertex(vertex146);
    auto vertex147 = new Vertex(406, 327);
    this->field.add_vertex(vertex147);
    auto vertex148 = new Vertex(376, 307);
    this->field.add_vertex(vertex148);
    auto vertex149 = new Vertex(331, 345);
    this->field.add_vertex(vertex149);
    auto vertex150 = new Vertex(297, 295);
    this->field.add_vertex(vertex150);
    auto vertex151 = new Vertex(255, 325);
    this->field.add_vertex(vertex151);
    auto vertex152 = new Vertex(274, 312);
    this->field.add_vertex(vertex152);
    auto vertex153 = new Vertex(216, 280);
    this->field.add_vertex(vertex153);
    auto vertex154 = new Vertex(147, 328);
    this->field.add_vertex(vertex154);
    auto vertex155 = new Vertex(264, 393);
    this->field.add_vertex(vertex155);
    auto vertex156 = new Vertex(229, 170);
    this->field.add_vertex(vertex156);
    auto vertex157 = new Vertex(201, 154);
    this->field.add_vertex(vertex157);
    auto vertex158 = new Vertex(178, 174);
    this->field.add_vertex(vertex158);
    auto vertex159 = new Vertex(151, 156);
    this->field.add_vertex(vertex159);
    auto vertex160 = new Vertex(162, 187);
    this->field.add_vertex(vertex160);
    auto vertex161 = new Vertex(135, 201);
    this->field.add_vertex(vertex161);
    auto vertex162 = new Vertex(108, 183);
    this->field.add_vertex(vertex162);
    auto vertex163 = new Vertex(13, 187);
    this->field.add_vertex(vertex163);
    auto vertex164 = new Vertex(144, 267);
    this->field.add_vertex(vertex164);
    auto vertex165 = new Vertex(16, 357);
    this->field.add_vertex(vertex165);
    auto vertex166 = new Vertex(70, 391);
    this->field.add_vertex(vertex166);
    auto vertex167 = new Vertex(40, 411);
    this->field.add_vertex(vertex167);
    auto vertex168 = new Vertex(61, 421);
    this->field.add_vertex(vertex168);
    auto vertex169 = new Vertex(33, 438);
    this->field.add_vertex(vertex169);
    auto vertex170 = new Vertex(63, 450);
    this->field.add_vertex(vertex170);
    auto vertex171 = new Vertex(37, 466);
    this->field.add_vertex(vertex171);
    auto vertex172 = new Vertex(97, 499);
    this->field.add_vertex(vertex172);
    auto vertex173 = new Vertex(36, 544);
    this->field.add_vertex(vertex173);
    auto vertex174 = new Vertex(109, 558);
    this->field.add_vertex(vertex174);
    auto vertex175 = new Vertex(57, 528);
    this->field.add_vertex(vertex175);
    auto vertex176 = new Vertex(156, 528);
    this->field.add_vertex(vertex176);
    auto vertex177 = new Vertex(142, 472);
    this->field.add_vertex(vertex177);
    auto vertex178 = new Vertex(112, 453);
    this->field.add_vertex(vertex178);
    auto vertex179 = new Vertex(181, 402);
    this->field.add_vertex(vertex179);
    auto vertex180 = new Vertex(244, 438);
    this->field.add_vertex(vertex180);
    auto vertex181 = new Vertex(291, 406);
    this->field.add_vertex(vertex181);
    auto vertex182 = new Vertex(387, 373);
    this->field.add_vertex(vertex182);
    auto vertex183 = new Vertex(415, 391);
    this->field.add_vertex(vertex183);
    auto vertex184 = new Vertex(387, 408);
    this->field.add_vertex(vertex184);
    auto vertex185 = new Vertex(316, 451);
    this->field.add_vertex(vertex185);
    auto vertex186 = new Vertex(442, 438);
    this->field.add_vertex(vertex186);
    auto vertex187 = new Vertex(465, 421);
    this->field.add_vertex(vertex187);
    auto vertex188 = new Vertex(487, 400);
    this->field.add_vertex(vertex188);
    auto vertex189 = new Vertex(493, 436);
    this->field.add_vertex(vertex189);
    auto vertex190 = new Vertex(540, 438);
    this->field.add_vertex(vertex190);
    auto vertex191 = new Vertex(571, 424);
    this->field.add_vertex(vertex191);
    auto vertex192 = new Vertex(543, 406);
    this->field.add_vertex(vertex192);
    auto vertex193 = new Vertex(571, 394);
    this->field.add_vertex(vertex193);
    auto vertex194 = new Vertex(538, 372);
    this->field.add_vertex(vertex194);
    auto vertex195 = new Vertex(564, 358);
    this->field.add_vertex(vertex195);
    auto vertex196 = new Vertex(351, 267);
    this->field.add_vertex(vertex196);
    auto vertex197 = new Vertex(373, 249);
    this->field.add_vertex(vertex197);
    auto vertex198 = new Vertex(402, 265);
    this->field.add_vertex(vertex198);
    auto vertex199 = new Vertex(294, 232);
    this->field.add_vertex(vertex199);
    auto vertex200 = new Vertex(316, 219);
    this->field.add_vertex(vertex200);
    auto vertex201 = new Vertex(264, 216);
    this->field.add_vertex(vertex201);
    auto vertex202 = new Vertex(238, 237);
    this->field.add_vertex(vertex202);
    auto vertex203 = new Vertex(211, 219);
    this->field.add_vertex(vertex203);
    auto vertex204 = new Vertex(352, 577);
    this->field.add_vertex(vertex204);
    auto vertex205 = new Vertex(261, 529);
    this->field.add_vertex(vertex205);
    auto vertex206 = new Vertex(303, 499);
    this->field.add_vertex(vertex206);
    auto vertex207 = new Vertex(245, 469);
    this->field.add_vertex(vertex207);
    auto vertex211 = new Vertex(87, 61);
    this->field.add_vertex(vertex211);
    auto vertex306 = new Vertex(345, 468);
    this->field.add_vertex(vertex306);
    auto vertex322 = new Vertex(213, 562);
    this->field.add_vertex(vertex322);
    auto vertex325 = new Vertex(190, 576);
    this->field.add_vertex(vertex325);
    auto vertex327 = new Vertex(384, 555); // Dit is de basis rechtsonder
    this->field.add_vertex(vertex327);
    this->field.add_edge(new Edge(vertex103, vertex104));
    this->field.add_edge(new Edge(vertex106, vertex105));
    this->field.add_edge(new Edge(vertex104, vertex105));
    this->field.add_edge(new Edge(vertex211, vertex104));
    this->field.add_edge(new Edge(vertex211, vertex108));
    this->field.add_edge(new Edge(vertex211, vertex107));
    this->field.add_edge(new Edge(vertex107, vertex109));
    this->field.add_edge(new Edge(vertex109, vertex112));
    this->field.add_edge(new Edge(vertex112, vertex111));
    this->field.add_edge(new Edge(vertex111, vertex111));
    this->field.add_edge(new Edge(vertex113, vertex112));
    this->field.add_edge(new Edge(vertex113, vertex114));
    this->field.add_edge(new Edge(vertex114, vertex115));
    this->field.add_edge(new Edge(vertex115, vertex116));
    this->field.add_edge(new Edge(vertex115, vertex117));
    this->field.add_edge(new Edge(vertex117, vertex198));
    this->field.add_edge(new Edge(vertex198, vertex197));
    this->field.add_edge(new Edge(vertex197, vertex196));
    this->field.add_edge(new Edge(vertex196, vertex199));
    this->field.add_edge(new Edge(vertex199, vertex200));
    this->field.add_edge(new Edge(vertex199, vertex201));
    this->field.add_edge(new Edge(vertex201, vertex202));
    this->field.add_edge(new Edge(vertex202, vertex203));
    this->field.add_edge(new Edge(vertex203, vertex160));
    this->field.add_edge(new Edge(vertex160, vertex158));
    this->field.add_edge(new Edge(vertex158, vertex159));
    this->field.add_edge(new Edge(vertex158, vertex157));
    this->field.add_edge(new Edge(vertex157, vertex156));
    this->field.add_edge(new Edge(vertex160, vertex161));
    this->field.add_edge(new Edge(vertex161, vertex162));
    this->field.add_edge(new Edge(vertex107, vertex163));
    this->field.add_edge(new Edge(vertex163, vertex164));
    this->field.add_edge(new Edge(vertex129, vertex130));
    this->field.add_edge(new Edge(vertex128, vertex129));
    this->field.add_edge(new Edge(vertex128, vertex127));
    this->field.add_edge(new Edge(vertex127, vertex126));
    this->field.add_edge(new Edge(vertex126, vertex123));
    this->field.add_edge(new Edge(vertex123, vertex124));
    this->field.add_edge(new Edge(vertex123, vertex125));
    this->field.add_edge(new Edge(vertex134, vertex135));
    this->field.add_edge(new Edge(vertex135, vertex136));
    this->field.add_edge(new Edge(vertex136, vertex137));
    this->field.add_edge(new Edge(vertex137, vertex138));
    this->field.add_edge(new Edge(vertex138, vertex139));
    this->field.add_edge(new Edge(vertex139, vertex121));
    this->field.add_edge(new Edge(vertex121, vertex122));
    this->field.add_edge(new Edge(vertex121, vertex123));
    this->field.add_edge(new Edge(vertex121, vertex120));
    this->field.add_edge(new Edge(vertex120, vertex119));
    this->field.add_edge(new Edge(vertex119, vertex118));
    this->field.add_edge(new Edge(vertex118, vertex117));
    this->field.add_edge(new Edge(vertex118, vertex142));
    this->field.add_edge(new Edge(vertex142, vertex140));
    this->field.add_edge(new Edge(vertex142, vertex141));
    this->field.add_edge(new Edge(vertex142, vertex143));
    this->field.add_edge(new Edge(vertex143, vertex144));
    this->field.add_edge(new Edge(vertex144, vertex145));
    this->field.add_edge(new Edge(vertex145, vertex146));
    this->field.add_edge(new Edge(vertex146, vertex147));
    this->field.add_edge(new Edge(vertex147, vertex148));
    this->field.add_edge(new Edge(vertex148, vertex149));
    this->field.add_edge(new Edge(vertex149, vertex152));
    this->field.add_edge(new Edge(vertex152, vertex150));
    this->field.add_edge(new Edge(vertex152, vertex151));
    this->field.add_edge(new Edge(vertex152, vertex153));
    this->field.add_edge(new Edge(vertex153, vertex154));
    this->field.add_edge(new Edge(vertex154, vertex166));
    this->field.add_edge(new Edge(vertex166, vertex165));
    this->field.add_edge(new Edge(vertex165, vertex164));
    this->field.add_edge(new Edge(vertex164, vertex203));
    this->field.add_edge(new Edge(vertex172, vertex171));
    this->field.add_edge(new Edge(vertex171, vertex170));
    this->field.add_edge(new Edge(vertex170, vertex169));
    this->field.add_edge(new Edge(vertex169, vertex168));
    this->field.add_edge(new Edge(vertex167, vertex166));
    this->field.add_edge(new Edge(vertex168, vertex167));
    this->field.add_edge(new Edge(vertex173, vertex175));
    this->field.add_edge(new Edge(vertex172, vertex175));
    this->field.add_edge(new Edge(vertex177, vertex172));
    this->field.add_edge(new Edge(vertex178, vertex177));
    this->field.add_edge(new Edge(vertex178, vertex179));
    this->field.add_edge(new Edge(vertex179, vertex180));
    this->field.add_edge(new Edge(vertex155, vertex181));
    this->field.add_edge(new Edge(vertex155, vertex149));
    this->field.add_edge(new Edge(vertex155, vertex154));
    this->field.add_edge(new Edge(vertex183, vertex182));
    this->field.add_edge(new Edge(vertex183, vertex184));
    this->field.add_edge(new Edge(vertex183, vertex145));
    this->field.add_edge(new Edge(vertex145, vertex194));
    this->field.add_edge(new Edge(vertex194, vertex195));
    this->field.add_edge(new Edge(vertex194, vertex193));
    this->field.add_edge(new Edge(vertex193, vertex192));
    this->field.add_edge(new Edge(vertex192, vertex191));
    this->field.add_edge(new Edge(vertex188, vertex187));
    this->field.add_edge(new Edge(vertex184, vertex185));
    this->field.add_edge(new Edge(vertex205, vertex204));
    this->field.add_edge(new Edge(vertex205, vertex206));
    this->field.add_edge(new Edge(vertex185, vertex306));
    this->field.add_edge(new Edge(vertex206, vertex306));
    this->field.add_edge(new Edge(vertex207, vertex206));
    this->field.add_edge(new Edge(vertex176, vertex207));
    this->field.add_edge(new Edge(vertex176, vertex174));
    this->field.add_edge(new Edge(vertex174, vertex175));
    this->field.add_edge(new Edge(vertex187, vertex186));
    this->field.add_edge(new Edge(vertex187, vertex189));
    this->field.add_edge(new Edge(vertex186, vertex184));
    this->field.add_edge(new Edge(vertex191, vertex190));
    this->field.add_edge(new Edge(vertex111, vertex110));
    this->field.add_edge(new Edge(vertex130, vertex131));
    this->field.add_edge(new Edge(vertex130, vertex132));
    this->field.add_edge(new Edge(vertex132, vertex125));
    this->field.add_edge(new Edge(vertex133, vertex134));
    this->field.add_edge(new Edge(vertex322, vertex176));
    this->field.add_edge(new Edge(vertex180, vertex181));
    this->field.add_edge(new Edge(vertex325, vertex322));
    this->field.add_edge(new Edge(vertex204, vertex327));
}

void BeeField::Draw()
{
    this->_draw_background();
    this->_draw_edges();
    this->_draw_vertices();
}

void BeeField::_draw_vertices()
{
    this->mApplication->SetColor(Color {0, 0, 255, 255});

    for (auto vertex : this->field.get_vertices()) {
        this->mApplication->DrawCircle(vertex->coordinates.x, vertex->coordinates.y, this->_vertex_draw_width, true);
    }
}

void BeeField::_draw_edges()
{
    this->mApplication->SetColor(Color {0,0,0,255});

    for (auto edge : this->field.get_edges()) {
        this->mApplication->DrawLine(
            edge->first->coordinates.x,
            edge->first->coordinates.y,
            edge->second->coordinates.x,
            edge->second->coordinates.y
        );
    }
}

void BeeField::_draw_background()
{
    this->mApplication->DrawTexture(this->_bg_image, 0, 0);
}

void BeeField::Update(float deltaTime)
{
    UNUSED(deltaTime)
    // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
}
