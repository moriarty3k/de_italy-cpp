//created by Hoang Dat and Huy Duc with love
//Quang Vu khong co cai tac dung gi??

#include <glut.h>
#include "imageloader.h"
#include "texturemodel.h"
#include "model.h"
#include <math.h>

namespace chiThoNgoc {
	Model name;
	TextureModel sky, skyTop, ground1, ground2, ground3, box, slope1, slope2, slope3, slope4, base1, house1, base2, house2, base3, house3,
		base4, base5, base6, base7, smallBase, wall1, wall2, wall3, wall4, wall5, wall6, fence1, fence2, window1, window2, roof1, roof2, roof3;
	Vector3 sky_t, skyTop_t, ground1_t, ground2_t, ground3_t, box_t1, box_t2, box_t3, box_t4, slope1_t, slope2_t, slope3_t, slope4_t, base1_t, base2_t, house1_t, house2_t, base3_t, house3_t,
		base4_t, base5_t, base6_t, base7_t, smallBase_t, wall1_t, wall2_t, wall3_t, wall4_t, wall5_t, wall6_t, fence1_t, fence2_t, window1_t1, window1_t2, window2_t1, window2_t2, window2_t3, roof1_t, roof2_t, roof3_t;
	float lx = 0.0f, ly = 0.0f, lz = 0.0f;
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float angle = -1.5f;
	float speed = 0.1f;
	float heightAngle = y;
	float height_view = -1;

	void draw(TextureModel* m, Vector3 t) {
		glPushMatrix();
		glTranslatef(t.x, t.y, t.z);
		m->draw();
		glPopMatrix();
	}

	void makeSky() {
		sky.clear();
		sky.setTextureFromBMP("data/sky.bmp");
		sky.addVertex(point3(-100, -100, -100));//0
		sky.addVertex(point3(100, -100, -100));//1
		sky.addVertex(point3(-100, 100, -100));//2
		sky.addVertex(point3(100, 100, -100));//3
		sky.addVertex(point3(-100, -100, 100));//4
		sky.addVertex(point3(100, -100, 100));//5
		sky.addVertex(point3(-100, 100, 100));//6
		sky.addVertex(point3(100, 100, 100));//7
		sky.addQuad(quadIndex(2, 3, 1, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(6, 7, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(2, 6, 4, 0, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		sky.addQuad(quadIndex(3, 7, 5, 1, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		sky_t = point3(0, 0, 0);
	}

	void makeSkyTop() {
		skyTop.clear();
		skyTop.setTextureFromBMP("data/skytop.bmp");
		skyTop.addVertex(point3(-100, 100, -100));
		skyTop.addVertex(point3(100, 100, -100));
		skyTop.addVertex(point3(100, 100, 100));
		skyTop.addVertex(point3(-100, 100, 100));
		skyTop.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		skyTop_t = point3(0, 0, 0);
	}

	void makeGround() {
		ground1.clear();
		ground1.setTextureFromBMP("texture/ground.bmp");
		ground1.addVertex(point3(-10, -1.5, 10));
		ground1.addVertex(point3(-10, -1.5, -10));
		ground1.addVertex(point3(10, -1.5, -10));
		ground1.addVertex(point3(10, -1.5, 10));
		ground1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 50), texCoord2(50, 50), texCoord2(50, 0), texCoord2(0, 0)));

		ground1_t = point3(0, 0, 0);

		ground2.clear();
		ground2.setTextureFromBMP("texture/stone.bmp");
		ground2.addVertex(point3(0, 1, 0));//0
		ground2.addVertex(point3(0, 1, -6));//1
		ground2.addVertex(point3(-4.5, 1, -6));//2
		ground2.addVertex(point3(-4.5, 1, 0));//3
		ground2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 4.5), texCoord2(6, 4.5), texCoord2(6, 0), texCoord2(0, 0)));

		ground2_t = point3(8.5, -1.5, -2);

		ground3.clear();
		ground3.setTextureFromBMP("texture/stone.bmp");
		ground3.addVertex(point3(-0.7, 1, -1));//0
		ground3.addVertex(point3(0.7, 1, -1));//1
		ground3.addVertex(point3(0.7, 1, 0));//2
		ground3.addVertex(point3(-0.7, 1, 0));//3
		ground3.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1.4, 1), texCoord2(1.4, 0), texCoord2(0, 0)));

		ground3_t = point3(3.3, -1.5, -2);
	}

	void makeBox() {
		box.clear();
		box.setTextureFromBMP("texture/box.bmp");
		box.addVertex(point3(-0.5, -0.5, 0));//0
		box.addVertex(point3(-0.5, 0.5, 0));//1
		box.addVertex(point3(0.5, 0.5, 0));//2
		box.addVertex(point3(0.5, -0.5, 0));//3
		box.addVertex(point3(-0.5, -0.5, 1));//4
		box.addVertex(point3(-0.5, 0.5, 1));//5
		box.addVertex(point3(0.5, 0.5, 1));//6
		box.addVertex(point3(0.5, -0.5, 1));//7

		box.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));
		box.addQuad(quadIndex(0, 3, 7, 4, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));
		box.addQuad(quadIndex(0, 4, 5, 1, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));
		box.addQuad(quadIndex(3, 7, 6, 2, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));
		box.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));
		box.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 0), texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0)));

		box_t1 = point3(7, 0, -3 - 0.0001);
		box_t2 = point3(-2.25 + 0.0001, -1, -6 - 0.0001);
		box_t3 = point3(5.5 - 0.0001, 0, 1 + 0.0001);
		box_t4 = point3(-5.5 + 0.0001, 0, 1 + 0.0001);
	}


	void makeSlope() {
		slope1.clear();
		slope1.setTextureFromBMP("texture/stone.bmp");
		slope1.addVertex(point3(-6, 1, 0));//0
		slope1.addVertex(point3(6, 1, 0));//1
		slope1.addVertex(point3(6, 0, -6));//2
		slope1.addVertex(point3(-6, 0, -6));//3
		slope1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 6), texCoord2(6, 6), texCoord2(6, 0), texCoord2(0, 0)));

		slope1_t = point3(0, -1.5, 7);

		slope2.clear();
		slope2.setTextureFromBMP("texture/stone.bmp");
		slope2.addVertex(point3(-0.7, 1, -1));//0
		slope2.addVertex(point3(0.7, 1, -1));//1
		slope2.addVertex(point3(0.7, 0, -4.5));//2
		slope2.addVertex(point3(-0.7, 0, -4.5));//3
		slope2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 3.5), texCoord2(1.4, 3.5), texCoord2(1.4, 0), texCoord2(0, 0)));

		slope2_t = point3(3.3, -1.5, -2);

		slope3.clear();
		slope3.setTextureFromBMP("texture/ground.bmp");
		slope3.addVertex(point3(-1.5, 1, 0));//0
		slope3.addVertex(point3(-0.35, 0, -6));//1
		slope3.addVertex(point3(-2.1, 0, -6));//2
		slope3.addVertex(point3(-3.25, 1, 0));//3
		slope3.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1.75*2.5), texCoord2( 6*2.5, 1.75*2.5), texCoord2(6*2.5, 0), texCoord2(0, 0)));

		slope3_t = point3(-0.35, -1.5 + 0.0001, 7);

		slope4.clear();
		slope4.setTextureFromBMP("texture/ground.bmp");
		slope4.addVertex(point3(1.5, 1, 0));//0
		slope4.addVertex(point3(0.35, 0, -6));//1
		slope4.addVertex(point3(2.1, 0, -6));//2
		slope4.addVertex(point3(3.25, 1, 0));//3
		slope4.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1.75 * 2.5), texCoord2(6 * 2.5, 1.75 * 2.5), texCoord2(6 * 2.5, 0), texCoord2(0, 0)));

		slope4_t = point3(0.35, -1.5 + 0.0001, 7);

	}

	void makeWall() {
		wall1.clear();
		wall1.setTextureFromBMP("texture/wall2.bmp");
		wall1.addVertex(point3(-5.5, 1, -6));//0
		wall1.addVertex(point3(-5.2, 1, -6));//1
		wall1.addVertex(point3(-5.2, 1, -9));//2
		wall1.addVertex(point3(-5.5, 1, -9));//3
		wall1.addVertex(point3(-5.5, 2, -6));//4
		wall1.addVertex(point3(-5.2, 2, -6));//5
		wall1.addVertex(point3(-5.2, 2, -9));//6
		wall1.addVertex(point3(-5.5, 2, -9));//7
		wall1.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(3, 1), texCoord2(3, 0), texCoord2(0, 0)));
		wall1.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 1), texCoord2(3, 1), texCoord2(3, 0), texCoord2(0, 0)));
		wall1_t = point3(2.25, -1.5, 1);

		wall2.clear();
		wall2.setTextureFromBMP("texture/wall1.bmp");
		wall2.addVertex(point3(0, 0, 0));//0
		wall2.addVertex(point3(11.5, 0, 0));//1
		wall2.addVertex(point3(11.5, 0, 1));//2
		wall2.addVertex(point3(0, 0, 1));//3
		wall2.addVertex(point3(0, 2, 0));//4
		wall2.addVertex(point3(11.5, 2, 0));//5
		wall2.addVertex(point3(11.5, 2, 1));//6
		wall2.addVertex(point3(0, 2, 1));//7
		wall2.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 2), texCoord2(11.5, 2), texCoord2( 11.5,0), texCoord2(0, 0)));
		wall2.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 2), texCoord2(11.5, 2), texCoord2(11.5,0), texCoord2(0, 0)));
		wall2.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 2), texCoord2(11.5, 2), texCoord2( 11.5,0), texCoord2(0, 0)));

		wall2_t = point3(-3, -1.5, -9);

		wall3.clear();
		wall3.setTextureFromBMP("texture/wall2.bmp");
		wall3.addVertex(point3(-4, 1, -6));//0
		wall3.addVertex(point3(-4, 1, 0));//1
		wall3.addVertex(point3(-4.5, 1, -6));//2
		wall3.addVertex(point3(-4.5, 1, 0));//3
		wall3.addVertex(point3(-4, 2, -6));//4
		wall3.addVertex(point3(-4, 2, 0));//5
		wall3.addVertex(point3(-4.5, 2, -6));//6
		wall3.addVertex(point3(-4.5, 2, 0));//7
		wall3.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(6, 1), texCoord2(6, 0), texCoord2(0, 0)));
		wall3.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(6, 1), texCoord2(6, 0), texCoord2(0, 0)));
		wall3.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(6, 1), texCoord2(6, 0), texCoord2(0, 0)));

		wall3_t = point3(12, -1.5, -2);

		wall4.clear();
		wall4.setTextureFromBMP("texture/wall2.bmp");
		wall4.addVertex(point3(0, 0, 0));//0
		wall4.addVertex(point3(0, 0, -6));//1
		wall4.addVertex(point3(0, 1, -6));//2
		wall4.addVertex(point3(0, 1, 0));//3
		wall4.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(6, 1), texCoord2(6, 0), texCoord2(0, 0)));

		wall4_t = point3(6, -0.5, 7);

		wall5.clear();
		wall5.setTextureFromBMP("texture/wall2.bmp");
		wall5.addVertex(point3(0, 0, 0));//0
		wall5.addVertex(point3(0, 0, -6));//1
		wall5.addVertex(point3(0, 1, -6));//2
		wall5.addVertex(point3(0, 1, 0));//3
		wall5.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(6, 1), texCoord2(6, 0), texCoord2(0, 0)));

		wall5_t = point3(-6, -0.5, 7);

		wall6.clear();
		wall6.setTextureFromBMP("texture/flower.bmp");
		wall6.addVertex(point3(0, 0, 0));//0
		wall6.addVertex(point3(12, 0, 0));//1
		wall6.addVertex(point3(12, 0, 1));//2
		wall6.addVertex(point3(0, 0, 1));//3
		wall6.addVertex(point3(0, 3, 0));//4
		wall6.addVertex(point3(12, 3, 0));//5
		wall6.addVertex(point3(12, 3, 1));//6
		wall6.addVertex(point3(0, 3, 1));//7
		wall6.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 3), texCoord2(12, 3), texCoord2(12, 0), texCoord2(0, 0)));
		wall6.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 3), texCoord2(12, 3), texCoord2(12, 0), texCoord2(0, 0)));
		wall6.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 3), texCoord2(12, 3), texCoord2(12, 0), texCoord2(0, 0)));

		wall6_t = point3(-6, -1.5, 7);
	}

	void makeBase() {
		base1.clear();
		base1.setTextureFromBMP("texture/wall1.bmp");
		base1.addVertex(point3(-1.5, 1, 0));//0
		base1.addVertex(point3(1.5, 1, 0));//1
		base1.addVertex(point3(0.35, 1, -6));//2
		base1.addVertex(point3(-0.35, 1, -6));//3
		base1.addVertex(point3(0.35, 0, -6));//4
		base1.addVertex(point3(-0.35, 0, -6));//5
		base1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base1.addQuad(quadIndex(2, 3, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base1.addTriangle(triangleIndex(1, 2, 4, texCoord2(0, 2), texCoord2(1, 0), texCoord2(0, 0)));
		base1.addTriangle(triangleIndex(0, 3, 5, texCoord2(0, 2), texCoord2(1, 0), texCoord2(0, 0)));

		base1_t = point3(0, -1.5, 7);

		base2.clear();
		base2.setTextureFromBMP("texture/wall1.bmp");
		base2.addVertex(point3(0, 0, 0));//0
		base2.addVertex(point3(0, 0, -3));//1
		base2.addVertex(point3(-6, 0, -3));//2
		base2.addVertex(point3(-6, 0, 0));//3
		base2.addVertex(point3(0, 1, 0));//4
		base2.addVertex(point3(0, 1, -3));//5
		base2.addVertex(point3(-6, 1, -3));//6
		base2.addVertex(point3(-6, 1, 0));//7
		base2.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base2.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base2.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		base2_t = point3(8.5, -1.5, 1);

		base3.clear();
		base3.setTextureFromBMP("texture/wall1.bmp");
		base3.addVertex(point3(0, 0, 0));//0
		base3.addVertex(point3(0, 0, -6));//1
		base3.addVertex(point3(-6, 0, -6));//2
		base3.addVertex(point3(-6, 0, 0));//3
		base3.addVertex(point3(0, 1, 0));//4
		base3.addVertex(point3(0, 1, -6));//5
		base3.addVertex(point3(-6, 1, -6));//6
		base3.addVertex(point3(-6, 1, 0));//7
		base3.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base3.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base3.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		base3_t = point3(-2.5, -1.5, 1);

		base4.clear();
		base4.setTextureFromBMP("texture/wall1.bmp");
		base4.addVertex(point3(0, 0, 0));//0
		base4.addVertex(point3(0, 0, -6));//1
		base4.addVertex(point3(-4.5, 0, -6));//2
		base4.addVertex(point3(-4.5, 0, 0));//3
		base4.addVertex(point3(0, 1, 0));//4
		base4.addVertex(point3(0, 1, -6));//5
		base4.addVertex(point3(-4.5, 1, -6));//6
		base4.addVertex(point3(-4.5, 1, 0));//7
		base4.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base4.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		base4.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		base4_t = point3(8.5, -1.5, -2);

		base5.clear();
		base5.setTextureFromBMP("texture/wall1.bmp");
		base5.addVertex(point3(-0.7, 1, -1));//0
		base5.addVertex(point3(0.7, 1, -1));//1
		base5.addVertex(point3(0.7, 0, -4.5));//2
		base5.addVertex(point3(-0.7, 0, -4.5));//3
		base5.addVertex(point3(-0.7, 1, 0));//4
		base5.addVertex(point3(0.7, 1, 0));//5
		base5.addVertex(point3(0.7, 0, 0));//6
		base5.addVertex(point3(-0.7, 0, 0));//7
		base5.addQuad(quadIndex(0, 3, 7, 4, texCoord2(0, 0), texCoord2(1, 1), texCoord2(0, 1), texCoord2(1, 0)));

		base5_t = point3(3.3, -1.5, -2);

		smallBase.clear();
		smallBase.setTextureFromBMP("texture/wall1.bmp");
		smallBase.addVertex(point3(-5.5, 1, -6));//0
		smallBase.addVertex(point3(-5, 1, -6));//1
		smallBase.addVertex(point3(-5, 1, -9));//2
		smallBase.addVertex(point3(-5.5, 1, -9));//3
		smallBase.addVertex(point3(-5.5, 0, -6));//4
		smallBase.addVertex(point3(-5, 0, -6));//5
		smallBase.addVertex(point3(-5, 0, -9));//6
		smallBase.addVertex(point3(-5.5, 0, -9));//7
		smallBase.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		smallBase.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		smallBase_t = point3(2.25, -1.5, 1);

		base6.clear();
		base6.setTextureFromBMP("texture/wall1.bmp");
		base6.addVertex(point3(1.5, 1, 0));//0
		base6.addVertex(point3(0.35, 1, -6));//1
		base6.addVertex(point3(0.35, 0, -6));//2
		base6.addVertex(point3(4, 1, 0));//3
		base6.addVertex(point3(4, 1, -6));//4
		base6.addVertex(point3(4, 0, -6));//5
		base6.addTriangle(triangleIndex(0, 1, 2, texCoord2(0, 2), texCoord2(1, 0), texCoord2(0, 0)));
		base6.addQuad(quadIndex(0, 1, 4, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		base6_t = point3(2.5, -1.5, 7);

		base7.clear();
		base7.setTextureFromBMP("texture/wall1.bmp");
		base7.addVertex(point3(-1.5, 1, 0));//0
		base7.addVertex(point3(-0.35, 1, -6));//1
		base7.addVertex(point3(-0.35, 0, -6));//2
		base7.addVertex(point3(-4, 1, 0));//3
		base7.addVertex(point3(-4, 1, -6));//4
		base7.addVertex(point3(-4, 0, -6));//5
		base7.addTriangle(triangleIndex(0, 1, 2, texCoord2(0, 2), texCoord2(1, 0), texCoord2(0, 0)));
		base7.addQuad(quadIndex(0, 1, 4, 3, texCoord2(0, 1), texCoord2(1, 4), texCoord2(4, 3), texCoord2(3, 0)));

		base7_t = point3(-2.5, -1.5, 7);

	}
	void makeHouse() {
		house1.clear();
		house1.setTextureFromBMP("texture/wall3.bmp");
		house1.addVertex(point3(-1.5, 1, 0));//0
		house1.addVertex(point3(1.5, 1, 0));//1
		house1.addVertex(point3(0.35, 1, -6));//2
		house1.addVertex(point3(-0.35, 1, -6));//3
		house1.addVertex(point3(-1.5, 3, 0));//4
		house1.addVertex(point3(1.5, 3, 0));//5
		house1.addVertex(point3(0.35, 3, -6));//6
		house1.addVertex(point3(-0.35, 3, -6));//7
		house1.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house1.addQuad(quadIndex(6, 2, 3, 7, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house1.addQuad(quadIndex(2, 6, 5, 1, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));

		house1_t = point3(0, -1.5, 7);

		house2.clear();
		house2.setTextureFromBMP("texture/wall3.bmp");
		house2.addVertex(point3(0, 1, 0));//0
		house2.addVertex(point3(0, 1, -3));//1
		house2.addVertex(point3(-6, 1, -3));//2
		house2.addVertex(point3(-6, 1, 0));//3
		house2.addVertex(point3(0, 3, 0));//4
		house2.addVertex(point3(0, 3, -3));//5
		house2.addVertex(point3(-6, 3, -3));//6
		house2.addVertex(point3(-6, 3, 0));//7
		house2.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house2.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house2.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));

		house2_t = point3(8.5, -1.5, 1);

		house3.clear();
		house3.setTextureFromBMP("texture/wall3.bmp");
		house3.addVertex(point3(0, 1, 0));//0
		house3.addVertex(point3(0, 1, -6));//1
		house3.addVertex(point3(-6, 1, -6));//2
		house3.addVertex(point3(-6, 1, 0));//3
		house3.addVertex(point3(0, 3, 0));//4
		house3.addVertex(point3(0, 3, -6));//5
		house3.addVertex(point3(-6, 3, -6));//6
		house3.addVertex(point3(-6, 3, 0));//7
		house3.addQuad(quadIndex(0, 1, 5, 4, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house3.addQuad(quadIndex(1, 2, 6, 5, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));
		house3.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 5), texCoord2(5, 5), texCoord2(5, 0), texCoord2(0, 0)));

		house3_t = point3(-2.5, -1.5, 1);
	}

	void makefence() {
		fence1.clear();
		fence1.setTextureFromBMP("texture/wooden.bmp");
		fence1.addVertex(point3(0, 0, 0));//0
		fence1.addVertex(point3(0, 0, -5));//1
		fence1.addVertex(point3(0, 0.3, -5));//2
		fence1.addVertex(point3(0, 0.3, 0));//3
		fence1.addVertex(point3(0.05, 0, 0));//4
		fence1.addVertex(point3(0.05, 0, -5));//5
		fence1.addVertex(point3(0.05, 0.3, -5));//6
		fence1.addVertex(point3(0.05, 0.3, 0));//7
		fence1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence1.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence1.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence1.addQuad(quadIndex(0, 4, 7, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		fence1_t = point3(4, -0.5, -3);

		fence2.clear();
		fence2.setTextureFromBMP("texture/wooden.bmp");
		fence2.addVertex(point3(0, 0, 0));//0
		fence2.addVertex(point3(0, 0, -1));//1
		fence2.addVertex(point3(0, 0.3, -1));//2
		fence2.addVertex(point3(0, 0.3, 0));//3
		fence2.addVertex(point3(0.05, 0, 0));//4
		fence2.addVertex(point3(0.05, 0, -1));//5
		fence2.addVertex(point3(0.05, 0.3, -1));//6
		fence2.addVertex(point3(0.05, 0.3, 0));//7
		fence2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence2.addQuad(quadIndex(4, 5, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence2.addQuad(quadIndex(3, 2, 6, 7, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));
		fence2.addQuad(quadIndex(1, 5, 6, 2, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		fence2_t = point3(2.6, -0.5, -2);
	}

	void makewindow() {
		window1.clear();
		window1.setTextureFromBMP("texture/windows1.bmp");
		window1.addVertex(point3(0, 0, 0));//0
		window1.addVertex(point3(0.5, 0, 0));//1
		window1.addVertex(point3(0.5, 1, 0));//2
		window1.addVertex(point3(0, 1, 0));//3
		window1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(0.5, 1), texCoord2(0.5, 0), texCoord2(0, 0)));

		window1_t1 = point3(-0.25, 0.3, 1 - 0.001);
		window1_t2 = point3(3, 0, -2 - 0.0001);

		window2.clear();
		window2.setTextureFromBMP("texture/windows2.bmp");
		window2.addVertex(point3(0, 0, 0));//0
		window2.addVertex(point3(0, 0, 1));//1
		window2.addVertex(point3(0, 1, 1));//2
		window2.addVertex(point3(0, 1, 0));//3
		window2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		window2_t1 = point3(2.5 - 0.001, 0, -1);
		window2_t2 = point3(-2.5 + 0.01, 0, -1);
		window2_t3 = point3(-2.5 + 0.01, 0, -4);

	}

	void makeRoof() {

		roof1.clear();
		roof1.setTextureFromBMP("texture/roof.bmp");
		roof1.addVertex(point3(-1.75, 0, 0));//0
		roof1.addVertex(point3(-0.35, 0, -6.5));//1
		roof1.addVertex(point3(0.35, 0, -6.5));//2
		roof1.addVertex(point3(1.75, 0, 0));//3
		roof1.addVertex(point3(0, 1.7, 0));//4

		roof1.addTriangle(triangleIndex(1, 0, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof1.addTriangle(triangleIndex(2, 1, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof1.addTriangle(triangleIndex(3, 2, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof1.addTriangle(triangleIndex(0, 3, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof1.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		roof1_t = point3(0, 1.5, 7);

		roof2.clear();
		roof2.setTextureFromBMP("texture/roof.bmp");
		roof2.addVertex(point3(0, 0, 0));//0
		roof2.addVertex(point3(0, 0, 4));//1
		roof2.addVertex(point3(7, 0, 4));//2
		roof2.addVertex(point3(7, 0, 0));//3
		roof2.addVertex(point3(3.5, 1.5, 2));//4

		roof2.addTriangle(triangleIndex(1, 0, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof2.addTriangle(triangleIndex(2, 1, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof2.addTriangle(triangleIndex(3, 2, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof2.addTriangle(triangleIndex(0, 3, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof2.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		roof2_t = point3(2, 1.5, -2.5);

		roof3.clear();
		roof3.setTextureFromBMP("texture/roof.bmp");
		roof3.addVertex(point3(0, 0, 0));//0
		roof3.addVertex(point3(0, 0, -7));//1
		roof3.addVertex(point3(7, 0, -7));//2
		roof3.addVertex(point3(7, 0, 0));//3
		roof3.addVertex(point3(3.5, 1.5, -3.5));//4

		roof3.addTriangle(triangleIndex(1, 0, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof3.addTriangle(triangleIndex(2, 1, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof3.addTriangle(triangleIndex(3, 2, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof3.addTriangle(triangleIndex(0, 3, 4, texCoord2(0, 1), texCoord2(1, 0), texCoord2(-1, 0)));
		roof3.addQuad(quadIndex(0, 1, 2, 3, texCoord2(0, 1), texCoord2(1, 1), texCoord2(1, 0), texCoord2(0, 0)));

		roof3_t = point3(-9, 1.5, 1.5);
	}

	void resize(int width, int height) {
		if (height == 0) height = 1;
		const float ar = (float)width / (float)height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
		gluPerspective(45.0f, ar, 0.1f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();

		gluLookAt(x, y, z,
			x + lx, height_view, z + lz,
			0.0f, 1.0f, 0.0f);

		glEnable(GL_TEXTURE_2D);

		draw(&sky, sky_t);
		draw(&skyTop, skyTop_t);
		/*for (int x1 = -5; x1 < 5; x1++) {
			for (int z1 = -5; z1 < 5; z1++) {
				Vector3 ground1_t;
				ground1_t.x = x1;
				ground1_t.z = z1;
				ground1_t.y = 0;

				draw(&ground1, ground1_t);
			}
		}*/

		draw(&ground1, ground1_t);
		draw(&ground2, ground2_t);
		draw(&ground3, ground3_t);
		draw(&box, box_t1);
		draw(&box, box_t2);
		draw(&box, box_t3);
		draw(&box, box_t4);
		draw(&slope1, slope1_t);
		draw(&slope2, slope2_t);
		draw(&slope3, slope3_t);
		draw(&slope4, slope4_t);
		draw(&base1, base1_t);
		draw(&house1, house1_t);
		draw(&base2, base2_t);
		draw(&house2, house2_t);
		draw(&base3, base3_t);
		draw(&house3, house3_t);
		draw(&base4, base4_t);
		draw(&base5, base5_t);
		draw(&base6, base6_t);
		draw(&base7, base7_t);
		draw(&smallBase, smallBase_t);
		draw(&wall1, wall1_t);
		draw(&wall2, wall2_t);
		draw(&wall3, wall3_t);
		draw(&wall4, wall4_t);
		draw(&wall5, wall5_t);
		draw(&wall6, wall6_t);
		draw(&fence1, fence1_t);
		draw(&fence2, fence2_t);
		draw(&window1, window1_t1);
		draw(&window1, window1_t2);
		draw(&window2, window2_t1);
		draw(&window2, window2_t2);
		draw(&window2, window2_t3);
		draw(&roof1, roof1_t);
		draw(&roof2, roof2_t);
		draw(&roof3, roof3_t);
		glutSwapBuffers();
		glFlush();
	}

	void processKeys(unsigned char key, int xx, int yy) {
		switch (key) {
		case '>':
			speed += 0.1;
			break;
		case '<':
			speed -= 0.1;
			break;
		case 'w':
			if (heightAngle < PI / 2) {
				heightAngle += 0.1;
				height_view = sin(heightAngle) - 0.5;
			}
			break;
		case 's':
			if (heightAngle > (-PI / 2)) {
				heightAngle -= 0.1;
				height_view = sin(heightAngle) - 1;
			}
			break;
		case 'a':
			angle -= 0.1f;
			lx = cos(angle);
			lz = sin(angle);
			break;
		case 'd':
			angle += 0.1f;
			lx = cos(angle);
			lz = sin(angle);
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}

	void processSpecialKeys(int key, int xx, int yy) {

		float fraction = speed;

		switch (key) {
		case GLUT_KEY_LEFT:
			x += lz * fraction;
			z -= lx * fraction;
			break;
		case GLUT_KEY_RIGHT:
			x -= lz * fraction;
			z += lx * fraction;
			break;
		case GLUT_KEY_UP:
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		/*case GLUT_KEY_PAGE_UP:
			y += ly * fraction;

			break;
		case GLUT_KEY_PAGE_DOWN:
			y -= ly * fraction;
			break;*/
		}glutPostRedisplay();
	}

	void init() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		lx = cos(angle);
		lz = sin(angle);


		makeSky();
		makeSkyTop();
		makeGround();
		makeBox();
		makeSlope();
		makeBase();
		makeHouse();
		makeWall();
		makefence();
		makewindow();
		makeRoof();
	}
}
int italy(int argc, char** argv) {
	//glutInit(&argc, argv);
	//Tạo cửa sổ window chạy chương trình
	glutInitDisplayMode(/*GLUT_DOUBLE | GLUT_RGBA | */GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("de_italy.exe");
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(chiThoNgoc::resize);
	glutKeyboardFunc(chiThoNgoc::processKeys);
	glutSpecialFunc(chiThoNgoc::processSpecialKeys);
	glutDisplayFunc(chiThoNgoc::renderScene);
	chiThoNgoc::init();

	glutMainLoop();
	return 0;
}
