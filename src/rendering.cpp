#include "rendering.hpp"

GLuint idShader[3];
int initGLDone = 0;
bool flagFilaire = false;
bool flagAnim = false;
float ratio = 1.0f;
unsigned int nb_ms_elapsed = 0;
unsigned int nb_ms_save = 0;
unsigned int idTexSkybox = 0;

// Camera parameters
double rayon = 300.0;
double angle_phy = 15.0;
double angle_theta = 45.0;
double x = 0.f;

// Parametres du monde et des transformations
double xmin = -400.0, ymin = -400.0, xmax = +400.0, ymax = +400.0;
Matrix4D projMatrix;
Matrix4D viewMatrix;
MatrixStack modelviewStack;
StandardMesh *repere = NULL;
StandardMesh *ground = NULL;
IndexedMesh *a_basic_wolf = NULL;
IndexedMesh *sphere = NULL;
IndexedMesh *cyl = NULL;
StandardMesh *cone = NULL;
float up = 30.0f;
float moveSpeed = 0.1f;

/***************************************************************************/
/*   FONCTIONS PRINCIPALES DE DESSIN                                       */
/***************************************************************************/
void initGL()
{
	/**********************************************
	 * GL BUSINESS - NE PAS CHERCHER A COMPRENDRE
	 **********************************************/
	projMatrix = Matrix4D::perspective(45.0, ratio, 1.0f, 2000.0f);

	idShader[0] = ShaderManager::loadShader("./shaders/flat_shading.vert", "./shaders/flat_shading.frag", false);
	idShader[1] = ShaderManager::loadShader("./shaders/tex_shading.vert", "./shaders/tex_shading.frag", false);
	printf("Shader initialized !\n");

	glUseProgram(idShader[1]);
	glActiveTexture(GL_TEXTURE0);
	createSkyBox();

	glUseProgram(idShader[0]);

	/*******************************************
	 * CREATION DES OBJETS DE BASE (CANONIQUES)
	 *******************************************/
	repere = createRepere(100.0f);
	repere->createVAO(); // Creation de l'objet dans OpenGL

	ground = basicRect(xmax - xmin, ymax - ymin);
	ground->createVAO(); // Creation de l'objet dans OpenGL

	// Le "basic wolf" est, en fait, un simple cube de taille 20
	a_basic_wolf = basicCube(20.0f);
	a_basic_wolf->createVAO(); // Creation de l'objet dans OpenGL

	// Une sphere de rayon 10 (représentée par 16 bandes de 32 triangles)
	sphere = basicSphere(10.0f, 16, 16);
	sphere->createVAO(); // Creation de l'objet dans OpenGL

	// Un cylindre de hauteur 20 et de rayon 5
	cyl = basicCylinder(20.0, 5.);
	cyl->createVAO(); // Creation de l'objet dans OpenGL

	// Un cone de hauteur 20 et de rayon 5
	cone = basicCone(20.0, 5.);
	cone->createVAO(); // Creation de l'objet dans OpenGL

	CHECK_GL;

	initGLDone = 1;
	printf("Initialisation is done !\n");
}

void drawGround()
{
	modelviewStack.pushMatrix();
	setFlatColor(0.4, .0, .0);
	modelviewStack.addRotation(-M_PI / 2, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addTranslation(Vector3D(-400.f, 0.0f, -400.f));
	updateMvMatrix(0);
	ground->draw();
	modelviewStack.popMatrix();
}

void drawBasicWolf()
{
	modelviewStack.pushMatrix();
	setFlatColor(.1, .1, .1);
	modelviewStack.addTranslation(Vector3D(0.0f, 0.0f, 10.0f + up));
	modelviewStack.addHomothety(Vector3D(2.0f, 1.0f, 1.0f));
	updateMvMatrix(0);
	a_basic_wolf->draw();
	modelviewStack.popMatrix();
}

void flammes(int coeff)
{
	// La pic de ses morts
	modelviewStack.pushMatrix();
	setFlatColor(1, 0.4, .0);
	modelviewStack.addTranslation(Vector3D(38.0f, 0.f, 16.0f + up));
	modelviewStack.addRotation(-MY_PI / 2 - coeff * (MY_PI) / 5, Vector3D(0.f, 0.f, 1.f));
	modelviewStack.addHomothety(Vector3D(0.50f, 0.70f, 0.40f));
	updateMvMatrix(0);
	cone->draw();
	modelviewStack.popMatrix();
}

void pascontent(int coeff1, int coeff2)
{
	modelviewStack.pushMatrix();
	setFlatColor(0, 0, 0);
	modelviewStack.addTranslation(Vector3D(30.0f, coeff1, 23.0f + up));
	modelviewStack.addRotation(coeff2 * MY_PI / 6, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addHomothety(Vector3D(0.1f, 0.3f, 0.05f));
	updateMvMatrix(0);
	a_basic_wolf->draw();
	modelviewStack.popMatrix();
}

void drawHeadWolf()
{
	modelviewStack.pushMatrix();
	setFlatColor(.2, .2, .2);
	modelviewStack.addTranslation(Vector3D(20.0f, 0.0f, 20.0f + up));
	modelviewStack.addHomothety(Vector3D(1.1f, 1.1f, 1.1f));
	updateMvMatrix(0);
	sphere->draw();
	modelviewStack.popMatrix();
}

void drawGambettes(float position_x, float position_y)
{
	modelviewStack.pushMatrix();
	setFlatColor(.2, .2, .2);
	modelviewStack.addTranslation(Vector3D(position_x, position_y, 20.0f));
	modelviewStack.addRotation(M_PI / 2, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addHomothety(Vector3D(0.7f, 0.7f, 0.7f));
	updateMvMatrix(0);
	cyl->draw();
	modelviewStack.popMatrix();
}

void drawPapattes(float position_x, float position_y)
{
	modelviewStack.pushMatrix();
	setFlatColor(.1, .1, .1);
	modelviewStack.addTranslation(Vector3D(position_x, position_y, 20.0f));
	modelviewStack.addRotation(M_PI / 2, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addHomothety(Vector3D(0.5f, 0.5f, 0.5f));
	updateMvMatrix(0);
	sphere->draw();
	modelviewStack.popMatrix();
}

void drawTail(float position_x)
{
	modelviewStack.pushMatrix();
	setFlatColor(.0, .0, .0);
	modelviewStack.addTranslation(Vector3D(position_x, .0f, 42.0f));
	modelviewStack.addRotation(M_PI / 2, Vector3D(0.f, 0.f, 1.f));
	modelviewStack.addHomothety(Vector3D(0.5f, 0.8f, 0.5f));
	updateMvMatrix(0);
	cone->draw();
	modelviewStack.popMatrix();
}

void drawOreilles(int coeff)
{
	// Oreilles de Michel
	modelviewStack.pushMatrix();
	setFlatColor(0.8, .0, .0);
	modelviewStack.addTranslation(Vector3D(20.0f, 0.0f, 20.0f + up));
	modelviewStack.addRotation(coeff * M_PI / 6, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addHomothety(Vector3D(1.1f, 1.1f, 1.1f));
	updateMvMatrix(0);
	cone->draw();
	modelviewStack.popMatrix();
}

void Pic2cMorts(float position_x)
{
	// La pic de ses morts
	modelviewStack.pushMatrix();
	setFlatColor(1, 0, 0);
	modelviewStack.addTranslation(Vector3D(position_x, 0.0f, 50.f));
	modelviewStack.addRotation(MY_PI / 2, Vector3D(1.f, 0.f, 0.f));
	modelviewStack.addHomothety(Vector3D(0.25f, 0.25f, 0.25f));
	updateMvMatrix(0);
	cone->draw();
	modelviewStack.popMatrix();
}

void yeuxGlobuleux(float position_y)
{
	// Les potits yeux de Michel
	modelviewStack.pushMatrix();
	setFlatColor(1., 1., 1.);
	modelviewStack.addTranslation(Vector3D(28.0f, position_y, 20.0f + up));
	modelviewStack.addHomothety(Vector3D(0.3f, 0.3f, 0.3f));
	updateMvMatrix(0);
	sphere->draw();
	modelviewStack.popMatrix();
}

void PupilleGlobuleuse(float position_y)
{
	// Les potits globules de Michel
	modelviewStack.pushMatrix();
	setFlatColor(.0, .0, .0);
	modelviewStack.addTranslation(Vector3D(31.0f, position_y, 20.0f + up));
	modelviewStack.addHomothety(Vector3D(0.1f, 0.1f, 0.1f));
	updateMvMatrix(0);
	sphere->draw();
	modelviewStack.popMatrix();
}

void laBouche()
{
	modelviewStack.pushMatrix();
	setFlatColor(1, 0, 0);
	modelviewStack.addTranslation(Vector3D(30.0f, 0.0f, 17.0f + up));
	modelviewStack.addHomothety(Vector3D(0.10f, 0.25f, 0.40f));
	updateMvMatrix(0);
	sphere->draw();
	modelviewStack.popMatrix();
}

void aile2LaMortQuiTue(int coeff, int coeff2)
{
	modelviewStack.pushMatrix();
	setFlatColor(0.2, 0.2, 0.2);
	modelviewStack.addHomothety(Vector3D(3.f, 3.f, 0.5f));
	modelviewStack.addTranslation(Vector3D(0.f, 0.f, 60.0f + up));
	modelviewStack.addRotation(coeff * M_PI / coeff2, Vector3D(1.f, 0.f, 0.f));
	updateMvMatrix(0);
	cone->draw();
	modelviewStack.popMatrix();
}

void drawGoodWolf()
{
	modelviewStack.pushMatrix();
	modelviewStack.addRotation(moveSpeed, Vector3D(0.f, 0.f, 1.f));
	modelviewStack.addTranslation(Vector3D(x, 0.f, 0.f));

	// Michel
	drawBasicWolf();
	drawHeadWolf();
	// Gambettes
	drawGambettes(12.0f, 6.0f);
	drawGambettes(12.0f, -6.0f);
	drawGambettes(-12.0f, 6.0f);
	drawGambettes(-12.0f, -6.0f);
	// Papattes
	drawPapattes(12.0f, 6.0f);
	drawPapattes(12.0f, -6.0f);
	drawPapattes(-12.0f, 6.0f);
	drawPapattes(-12.0f, -6.0f);
	drawTail(-20.0f);
	drawTail(-25.0f);
	drawTail(-30.0f);

	// Oreilles
	drawOreilles(1);
	drawOreilles(3);
	drawOreilles(5);

	Pic2cMorts(-15.f);
	Pic2cMorts(-10.f);
	Pic2cMorts(-5.f);
	Pic2cMorts(0.f);
	Pic2cMorts(5.f);

	yeuxGlobuleux(6.0f);
	yeuxGlobuleux(-6.0f);
	PupilleGlobuleuse(-6.0f);
	PupilleGlobuleuse(6.0f);

	aile2LaMortQuiTue(1, 4);
	aile2LaMortQuiTue(3, 4);

	flammes(0);
	flammes(-1);
	flammes(1);
	pascontent(-5, -1);
	pascontent(5, 1);
	laBouche();
	modelviewStack.popMatrix();
	moveSpeed += 0.02;
}

void drawAnimal()
{
}

void drawScene(void)
{
	/*****************************************
	 * GL BUSINESS - DO NOT TRY TO UNDERSTAND
	 *****************************************/
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	if (flagFilaire)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	CHECK_GL;
	glUseProgram(idShader[0]);
	glUniformMatrix4fv(glGetUniformLocation(idShader[0], "projectionMat"), 1, GL_FALSE, projMatrix);
	glUseProgram(idShader[1]);
	glUniformMatrix4fv(glGetUniformLocation(idShader[1], "projectionMat"), 1, GL_FALSE, projMatrix);
	glUseProgram(idShader[0]);

	/***************************************
	 * CAMERA SETTING
	 ***************************************/
	Vector3D pos_camera = Vector3D(rayon * cos(deg2rad(angle_theta)) * cos(deg2rad(angle_phy)),
								   rayon * sin(deg2rad(angle_theta)) * cos(deg2rad(angle_phy)),
								   rayon * sin(deg2rad(angle_phy)));
	Vector3D viewed_point = Vector3D(0.0, 0.0, 0.0);

	Vector3D up_vector = Vector3D(0.0, 0.0, 1.0); // DO NOT TOUCH IT
	viewMatrix = Matrix4D::lookAt(pos_camera, viewed_point, up_vector);
	CHECK_GL;

	/***************************************
	 * DESSIN DE LA SCENE
	 ***************************************/
	modelviewStack.pushMatrix();
	modelviewStack.addTransformation(viewMatrix);
	updateMvMatrix(0);

	// DESSIN DE LA SKY BOX : NE PAS TOUCHER
	drawSky();

	// DESSIN DU REPERE DU MONDE
	repere->draw();

	// DESSIN DU SOL
	drawGround();

	// DESSIN DU LOUP
	drawGoodWolf();

	modelviewStack.popMatrix();

	// Verification des erreurs OpenGL
	CHECK_GL;
}
