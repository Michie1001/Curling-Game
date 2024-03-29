/*-----------------------------------------------------------
  Simulation Header File
  -----------------------------------------------------------*/
#include"vecmath.h"
#include <string>
#include <vector>
#include <iostream>

/*-----------------------------------------------------------
  Macros
  -----------------------------------------------------------*/
#define TABLE_X			(0.6f) 
#define TABLE_Z			(1.2f)
#define TABLE_Y			(0.1f)
#define BALL_RADIUS		(0.05f)
#define BALL_MASS		(0.1f)
#define TWO_PI			(6.2832f)
#define	SIM_UPDATE_MS	(10)
#define NUM_BALLS		(7)		
#define NUM_CUSHIONS	(4)		
#define NUM_SHEETS	(2)		

// #define MAX_PARTICLES	(200)
/*-----------------------------------------------------------
  plane normals
  -----------------------------------------------------------*/
/*
extern vec2	gPlaneNormal_Left;
extern vec2	gPlaneNormal_Top;
extern vec2	gPlaneNormal_Right;
extern vec2	gPlaneNormal_Bottom;
*/


/*-----------------------------------------------------------
  cushion class
  -----------------------------------------------------------*/
class cushion
{
public:
	vec2	vertices[2]; //2d
	vec2	centre;
	vec2	normal;

	void MakeNormal(void);
	void MakeCentre(void);
};

/*-----------------------------------------------------------
  ball class
  -----------------------------------------------------------*/

class ball
{
	static int ballIndexCnt;
public:
	vec2	position;
	vec2	velocity;
	float	radius;
	float	mass;
	int		index;

	ball(): position(0.0), velocity(0.0), radius(BALL_RADIUS), 
		mass(BALL_MASS) {
		index = ballIndexCnt++; 
		Reset();
	}
	

	void Reset(void);
	void ApplyImpulse(vec2 imp);
	void ApplyFrictionForce(int ms);
	void DoPlaneCollision(const cushion &c);
	void DoBallCollision(ball &b);
	void Update(int ms);
	
	bool HasHitPlane(const cushion &c) const;
	bool HasHitBall(const ball &b) const;

	void HitPlane(const cushion &c);
	void HitBall(ball &b);
};


/*-----------------------------------------------------------
  team class...commented out because it caused an 'exit':redefinition; 'noreturn' differs error
  -----------------------------------------------------------*/
//class team {
//private:
	//std::string name;
	//int score;
	//std::vector<int> playerScores;

//public:
	//team(const std::string& teamName) : name(teamName), score(0) {}

	//std::string getName() const {
		//return name;
	//}

	//int getScore() const {
		//return score;
	//}

	//void updateScore(int distance) { 
		//score += distance;
		//playerScores.push_back(distance);
	//}

	//void displayPlayerScores() const {
		//std::cout << "Player scores for Team " << name << ":\n";
		//for (int i = 0; i < playerScores.size(); i++) {
			//std::cout << "Player " << (i + 1) << ": " << playerScores[i] << "\n";
		//}
	//}
//};

/*-----------------------------------------------------------
  table class
  -----------------------------------------------------------*/
class table
{
public:
	ball balls[NUM_BALLS];	
	cushion cushions[NUM_CUSHIONS];
	//team team;

	void SetupCushions(void);
	void Update(int ms);	
	bool AnyBallsMoving(void) const;
};

/*-----------------------------------------------------------
  global table
  -----------------------------------------------------------*/
extern table gTable;
