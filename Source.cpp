//Code by Giovanni Miliziano
// 11/12/2018


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


struct rectz
{
	SDL_Rect plat;
	bool hit = false;
};
struct droppingobject
{
	SDL_Texture* texture;
	SDL_Rect rect;
};
struct bulletobject
{
	bool hit;
	SDL_Texture* texture;
	SDL_Rect rect;
	bool out;
	double b;
};
struct bombobject
{
	double angle;
	double addedwidth;
	bool hit;
	SDL_Texture* texture;
	SDL_Rect rect;
	bool out;
	double b;
	double width;
	double speed;
	int dir;
};
//gravity related 10
int gravityspeed = 8;
SDL_Rect ground = { 0,585,2000,50 };
bool jumpagain = true;
bool secondjump = false;
bool keyletgo = false;
int jumpframes = 0;
bool jumpstopglitch = false; //when you double jump, get on platform then instantly jump again
int safespacecounter = 0;
//
bool onetime = false;
bool gameover = false;
//435 y position
const double PI = 3.14;
int ball1upper = 1;
int ball11upper = 1;
char playerpos;
double playerx = 0;
double playery = 30;
int velocityspeed = 10;
int playervelx = 0;
int playervely = 0;
SDL_Rect heartman = { playerx,playery,75,75 };
SDL_Rect heartclip = { 50,25,225,300 };

bool ballswitch = false;
bool ball1switch = false;
int slowball1 = 0;
int ball1x = 1100;
int ball1y = 500;
int ball11x = 200;
int ball11y = 500;
int ball2x = 100;
int ball2y = 500;
bool ball2yswitch = false;
bool ball2xswitch = false;
int math2number = 0;
int ball2xmarkpoint = 0;
int ball2xmovement = 0;
bool ball2xswitchfirsttime = false;
int ball2ymarkpoint = 0;
int ball2ymovement = 0;
bool ball2yswitchfirsttime = false;

int ball3upper = 1;
int ball3x = 1100;
int ball3y = 500;
bool ball3switch = false;

bool trap5 = false;
int yellowbarneyx = 1200;
bool yellowbarneyfirst = true;
bool onetime5 = true;
int blooddropcounter = 0;
int headangle = 0;
int trapwall2y = 135;

bool onetime6 = true;
int blooddropcounter6 = 0;
int framecount6 = 0;
bool hit[10] = { 0,0,0,0,0,0,0,0,0,0 };
bool yellowbarneyfirst6 = true;
int yellowbarneyx6 = 1200;
int goback6 = 0;
bool ladderon = false;

bool jailwall7 = false;
bool chickengrab = false;
bool dontrenderwhite7 = false;
int tryhard7y = 700;
int tryhard77y;
int tryhard7x = -200;
int yellowbarney7x = 150;
int chicken7x = 200;
int chicken7y = 100;
bool beggining7 = true;
bool onetime7 = true;
bool firsttrihard = true;
int trihardcounter = 0;
droppingobject trihards[10];
bool shoottrihards = false;
int ball71x = 700;
int ball71y = 85;
int ball7radius = 75;
int ball72x = 900;
int ball72y = 85;
int angle7 = 100;
int spinangle = 0;
int screenwidth = 1200;
int screenheight = 650;

//background 8
int ball81x = 100;
int ball81y = 200;
int ball82x = 200;
int ball82y = 200;
int ball83x = 300;
int ball83y = 200;
int ball8radius = 100;
int angle8 = 0;
int angle82 = 0;
int angle83 = 0;
int sjw82x = 180;
int sjw81x = 180;
int sjw81y = 200;
bool sjw81ltor = true;
bool sjw81utod = true;
bool sjw82switch = false;
int sjw82angle = 0;
int sjw81b = 20;
bool wall1red = true;
bool wall2red = false;
bool wall3red = false;
bool wall4red = false;
bool wall5red = false;
int wall8counter = 0;
droppingobject trihards8[10];
bool onetime8 = true;
bool shoottrihards8 = true;
int smorc8y = -100;
bool smorcfall = false;
int chicken8x;
int chicken8y;
int trihard8x = -100;
int trihard8y = -100;
bool spawntrihard8 = false;
bool twitchalive = false;
int twitch8x = -1000;
int twitch8y = -1000;
int box8y = 160;
bool hittryhard = false;
int trihardangle8 = 0;
int trihard8w = 100;
int trihard8h = 200;
bool wallgone = false;
int wall85x = 1180;
int wall85y = 20;
// background 9
int chicken9x = playerx + 50;
int chicken9y = playery;
int lever9x = 900;
int lever9y = 545;
int chickenbucketz9x = 890;
int chickenbucketz9y = 480;
bool levergo = false;
int chicken9h = 50;
int stonewall9h = 595;
//background 10
int boshy10x = 700;
int boshy10y = 535;
bool grabboshi = false;
bool boshishoot = false;

//12
bool noground = false;

//background 16
bool greenbutton = false;
bool whitebutton = false;
bool brownbutton = false;
int greenbuttony = 570;
int whitebuttony = 570;
int brownbuttony = 570;
int greenbuttonh = 25;
int whitebuttonh = 25;
int brownbuttonh = 25;
int lilpumpx = -100;
int lilpumpy = -100;
int lilpumph = 100;
int lilpumpw = 100;
int lilpumpangle = 0;
bool lilpumpp1 = 0;
bool lilpumpp2 = 0;
bool lilpumpp3 = 0;
bool lilpumpp4 = 0;
bool lilpumpp5 = 0;
bool lilpumpup = 1;
bulletobject chainz[50];
int currentchainz = 0;
int chainzcounter = 0;
int chainzspeed = 40;
int lilpumphealth = 40;
bool playonce = 1;
int anelex = -600;
int aneley = -200;
int anelew = 100;
int aneleh = 100;
int aneleangle = 0;
int uslogox = -700;
int uslogoy = -700;
int uslogo2x = -700;
int uslogo2y = -700;
bool aneleright = 1;
bombobject bombz[21];
int bombzcounter = 0;
int currentbomz = 0;
int rbutton1y = -50;
int rbutton2y = -50;
bool press1 = 0;
bool press2 = 0;
bool press3 = 0;
int rocketx = -1000;
int rockety = -1000;
bool anelealive = 1;
int pausetimer = 0;
int anelemoveup = 0;
bool haltlilpump = 0;
bool haltallah = 0;
int tigercounter = 0;
int tigerx = 1100;
int tigery = 400;
int tigerangle = 0;
int tigerwoodshealth = 113;
int tigerh = 200;
bool halttiger = 0;
int wall16h = 600;
int cfourx = 2000;

//backgournd 19
int ratx = 400;
int raty = 535;
int mitchjonesx = -100;
int mitchjonesy = -100;
int mitchangle = 0;
bool mitchjonesspawn = 0;
bool mitchjoneslaser = 0;
int bluelaserx = -200;
int bluelasery = -200;
int bluelaserw = 100;
int bluelaserh = 150;
bool mitchmoveup = 1;
bool mitchmovedown = 0;
//to test stage four put stage four to 1 stage one to 0
bool stageone = 1;
bool stagetwo = 0;
bool stagethree = 0;
bool stagefour = 0;
bool stagefive = 0;
bool stagesix = 0;
bool stageseven = 0;
bool stageeight = 0;
bool stagenine = 0;
bool stageten = 0;
bulletobject fallingblast[30];
bool stagetwofirsttime = 1;
int currentblast = 0;
int blastcounter = 0;
int randomcounter = 100;
bulletobject shootingblast[10];
int currentshootingblast = 0;
int shootingblastcounter = 0;
int shootlasercounter = 1;
int lasercharge = 0;
bool apebuttonpress = 0;
int apechickenx = -300;
int apechickeny = -300;
int apesoundnumber = 0;
bool apebuttononce = 1;
bool stagethreeonce = 1;
bombobject pissbottles[15];
int pissbottlecounter = 1;
int currentpissbottle = 0;
bool stagefouronce = 1;
bool sodabuttonpress = 0;
int sodax = -300;
int soday = -300;
int shovelx = -300;
int shovely = -300;
int sodabuttontimer = 0;
bool stagefiveonce = 1;
bombobject dramashots[15];
int dramashotcounter = 1;
int currentdrama = 0;
double sodacirclex = 0;
double sodacircley = 0;
double sodacircleradius = 500;
int randomsong = 0;
bool shovelgrab = 0;
int sodalife = 5;
int giantbottlex = -1000;
int giantbottley = -1000;
bool bottleonce = 1;
bool sodarun = 0;
int sodacurrentsong = 1;
int sodaruncounter = 0;
bool stagesixonce = 1;
int mitchcircleangle = 0;
bombobject pyroblasts[15];
int pyroblastcounter = 1;
int currentpyroblast = 0;
int stagesixendcounter = 1;
int mirax = -500;
int miray = -500;
bool stagesevenonce = 1;
int plat1y = 390;
int plat2y = 390;
int plat3y = 262;
int platformy = 585;
SDL_Rect miraplatforms[10];
int miraplatformcounter = 1;
int currentmiraplatform = 0;
int miraplatformx1count = 0;
int miraplatformx2count = 0;
int miraplatformx3count = 0;
int miraplatformx4count = 0;
int kgbx = -1000;
int kgby = -1000;
bool kgbgoleft = 0;
bool kgbgoright = 1;
double kgbperiod = .002;
int kgbamplitude = 300;
droppingobject fallingrocks[5];
bombobject fallingrockhelp[5];
int currentrock = 0;
int kgbspeed = 2;
bool miramove = 0;
bool mitchspin = 0;
bool mitchmove = 1;
bool miragone = 0;
bombobject brokenrecords[10];
int currentbrokenrecord = 0;
int mitchhealthw = 150;
bool mitchexposed = 0;
int mitchhealth = 150;
bool mitchdead = 0;
bulletobject patricks[5];
bool stageeightonce = 1;
int currentpatrick = 0;
int patrickcounter = 1;
int patrickx = -1000;
int patricky = -1000;
bool patrickmove = 0;
int button119y = -1000;
int button219y = 300;
int button319y = 400;
int button419y = 500;
int button1119y = 0;
int button2219y = 0;
int button3319y = 0;
int button4419y = 0;

bool background19once = 1;
bool mirafight1 = 1;
bool mirafight2 = 1;
bool mitchfight11 = 0;
bool stagenineonce = 1;
int monologuecounter = 1;
bool mitchbye = 0;
bool stagetenonce = 1;
bool notonwow = 1;
bool brokenrecordsound = 1;
bool ratcanttouch = 0;
int platformx = 100;
bool platformspawn = 0;
int Stonex = -1000;
int Stoney = -1000;
int death = 0;
bool mitchfirsthalt = 1;
int randomlaser = rand() % 200 + 450;
const Uint8* currentkeystatereset = SDL_GetKeyboardState(0);

//20-22
int robloxhealth1 = 10;
int robloxhealth2 = 20;
bool roblox1dead = 0;
bool roblox2dead = 0;
int roblox2y = 350;
int roblox1y = 350;
//barney
int barneyx = 500;
int barneyy = 250;
int barneyw = 200;
int barneyh = 200;
int demonx = -900;
int demony = -1000;
bool barneysound1 = 1;
bool barneysound2 = 1;
bool barneysound3 = 1;
bool barneysound4 = 1;
bool barneysound5 = 1;
bool barneysound6 = 1;
bool barneymove = 1;
bombobject barneylaser[5];
bombobject demonlaser[5];
bool barneyonce = 0;
int currentbarneylaser = 0;
int currentdemonlaser = 0;
int lasercounter = 1;
bool barneybiglaser = 0;
int laserw = 1000;
int laserx = 1000;
double laserangle = 150;
bool lilpumpfall = 0;
int lilpump22y = -105;
int lilpumpfallcounter = 0;
bool lilpumplaughonce = 1;
bool barneyheadspawn = 0;
int barneyheadx = 900;
int barneyheady = 500;
int barneyhead2x = -100;
bool barneyset = 0;
bool dontshowbutton = 0;
int platFormy = 600;
bool perfectboyplay = 1;
bool cheeronce = 1;

//shooting
bulletobject bullets[5];
bool bulletspawn = true;
int currentbullet = 0;
SDL_Texture* dot = 0;
SDL_Window* gwindow = 0;
SDL_Renderer* grender = 0;
SDL_Surface* gsurface = 0;
TTF_Font* gfont = 0;
SDL_Texture* currentsurface = 0; //************
SDL_Texture* safespacemenu = 0;
SDL_Texture* menu1 = 0;
SDL_Texture* menu2 = 0;
SDL_Texture* textpage = 0;
SDL_Texture* boshytext = 0;
SDL_Texture* credits1 = 0;
SDL_Texture* credits2 = 0;
SDL_Texture* scotttext = 0;
SDL_Texture* safespacetext = 0;
SDL_Texture* credits3 = 0;
SDL_Texture* brandontalk = 0;
SDL_Texture* roberttalk = 0;
SDL_Texture* nextz = 0;
SDL_Texture* instructions = 0;
SDL_Texture* barneytalk = 0;
SDL_Texture* background = 0;
SDL_Texture* background2 = 0;
SDL_Texture* background3 = 0;
SDL_Texture* background4 = 0;
SDL_Texture* background5 = 0;
SDL_Texture* background6 = 0;
SDL_Texture* background7 = 0;
SDL_Texture* background8 = 0;
SDL_Texture* background9 = 0;
SDL_Texture* background10 = 0;
SDL_Texture* background11 = 0;
SDL_Texture* background12 = 0;
SDL_Texture* background13 = 0;
SDL_Texture* background14 = 0;
SDL_Texture* background15 = 0;
SDL_Texture* background16 = 0;
SDL_Texture* background17 = 0;
SDL_Texture* background18 = 0;
SDL_Texture* background19 = 0;
SDL_Texture* background20 = 0;
SDL_Texture* background21 = 0;
SDL_Texture* background22 = 0;
SDL_Texture* background23 = 0;
SDL_Texture* background24 = 0;
SDL_Texture* background25 = 0;
SDL_Texture* background26 = 0;
SDL_Texture* heart1 = 0;
SDL_Texture* heart2 = 0;
SDL_Texture* currentheart = 0;
int heartcount = 0;
SDL_Texture* heart3 = 0;
SDL_Texture* heart4 = 0;
SDL_Texture* ball1 = 0;
SDL_Texture* ball2 = 0;
SDL_Texture* ball3 = 0;
SDL_Texture* spike = 0;
SDL_Texture* friedchicken = 0;
SDL_Texture* kid1 = 0;
SDL_Texture* kid2 = 0;
SDL_Texture* kid3 = 0;
SDL_Texture* yellowbarney = 0;
SDL_Texture* yellowbarneyevil = 0;
SDL_Texture* whitebackground = 0;
SDL_Texture* blooddrop = 0;
SDL_Texture* ladder = 0;
SDL_Texture* smorc = 0;
SDL_Texture* twitch = 0;
SDL_Texture* dorito = 0;
SDL_Texture* opopie = 0;
SDL_Texture* hotpokket = 0;
SDL_Texture* fourhead = 0;
SDL_Texture* penguin = 0;
SDL_Texture* chickenbucket = 0;
SDL_Texture* stonewall = 0;
SDL_Texture* boshy = 0;
SDL_Texture* apple = 0;
SDL_Texture* hole = 0;
SDL_Texture* hole2 = 0;
SDL_Texture* dirt = 0;
SDL_Texture* rock = 0;
SDL_Texture* windowsxp = 0;
SDL_Texture* ubuntu = 0;
SDL_Texture* lilpump1 = 0;
SDL_Texture* lilpump2 = 0;
SDL_Texture* wrist1 = 0;
SDL_Texture* wrist2 = 0;
SDL_Texture* wrist3 = 0;
SDL_Texture* lilpumpcurrent;
SDL_Texture* explosion = 0;
SDL_Texture* bomb = 0;
SDL_Texture* anele = 0;
SDL_Texture* uslogo = 0;
SDL_Texture* missile = 0;
SDL_Texture* missile2 = 0;
SDL_Texture* tigerwoods = 0;
SDL_Texture* cfour = 0;
SDL_Texture* darkstone = 0;
SDL_Texture* cave = 0;
SDL_Texture* hangingbridge = 0;
SDL_Texture* princesspalace = 0;
SDL_Texture* lava = 0;
SDL_Texture* rat = 0;
SDL_Texture* mitchjones = 0;
SDL_Texture* bluelaser = 0;
SDL_Texture* arcaneblast = 0;
SDL_Texture* apechicken = 0;
SDL_Texture* apecharge = 0;
SDL_Texture* pissbottle = 0;
SDL_Texture* sodaw = 0;
SDL_Texture* shovel = 0;
SDL_Texture* luckfea = 0;
SDL_Texture* content = 0;
SDL_Texture* cx = 0;
SDL_Texture* dramajones = 0;
SDL_Texture* oldsodafeelsbadman = 0;
SDL_Texture* residentsleeper = 0;
SDL_Texture* brosbeforehoes = 0;
SDL_Texture* frostnova = 0;
SDL_Texture* sodadead = 0;
SDL_Texture* sodanope = 0;
SDL_Texture* arcane = 0;
SDL_Texture* fire = 0;
SDL_Texture* pyroblast = 0;
SDL_Texture* miraw = 0;
SDL_Texture* kgb = 0;
SDL_Texture* arock = 0;
SDL_Texture* brokenrecord = 0;
SDL_Texture* patrickdick = 0;
SDL_Texture* mitchbar = 0;
SDL_Texture* mitchfunny = 0;
SDL_Texture* warning = 0;
SDL_Texture* robloxman = 0;
SDL_Texture* robloxman2 = 0;
SDL_Texture* youshallnotpass = 0;
SDL_Texture* demon = 0;
SDL_Texture* evilbarney = 0;
SDL_Texture* evilbarney2 = 0;
SDL_Texture* barney = 0;
SDL_Texture* laserr = 0;
SDL_Texture* deathball = 0;
SDL_Texture* evilbarneyhead = 0;
SDL_Texture* brandon = 0;
SDL_Texture* robert = 0;
SDL_Texture* scottfitzgerald = 0;
SDL_Texture* stage = 0;

int bossinvinciblecounter = 0;
bool BossInvincible = false;
int angle = 1;
int ball4x = 400;
int ball4y = 200;
int ball4ycenter = 350;
int ball4xcenter = 535;
int ball4radius = 150;
int ball4counter = 0;
bool ballswitch4 = false;
bool ball4reverse = false;
int chickeny = 425;
int tryhardy = 650;
int tryhardx = 450;
bool tryhardreset = true;
bool tryhardspawn = false;
SDL_Texture* TryHard = 0;
int jumpcount = 0;
int platform = 0;
int pastplatform = 0;
int pastplaty;
int currentplaty;
bool tohigherplat = false;
int pastyposition = playery - 10; //to help see if player is going down or up offset by like 10
bool goingdown = false; //helps to see if player is going down or up
int pastypositioncounter = 0;
bool platchange = false;
Mix_Music* perfectboy = 0;
Mix_Music* fleshandbones = 0;
Mix_Music* titlesong = 0;
Mix_Music* barneytheme = 0;
Mix_Chunk* pokigasm = 0;
Mix_Chunk* scream = 0;
Mix_Chunk* barneyroar = 0;
Mix_Chunk* oof = 0;
Mix_Chunk* donttouchme = 0;
Mix_Chunk* thisisrape = 0;
Mix_Chunk* buttonpress = 0;
Mix_Chunk* doorbreak = 0;
Mix_Chunk* macearrape = 0;
Mix_Chunk* windowsearrape = 0;
Mix_Chunk* gunsound = 0;
Mix_Chunk* esketit = 0;
Mix_Chunk* oohlilpump = 0;
Mix_Music* hundredonmywrist = 0;
Mix_Music* allahmusic = 0;
Mix_Chunk* lilpumplaugh = 0;
Mix_Chunk* explosionsound = 0;
Mix_Chunk* missilesound = 0;
Mix_Chunk* tigerwoodsnews = 0;
Mix_Chunk* tigerwoodscheer = 0;
Mix_Music* mitchjonessong = 0;
Mix_Music* scarymusic = 0;
Mix_Chunk* motel6 = 0;
Mix_Chunk* hiyaa = 0;
Mix_Chunk* omegashenron = 0;
Mix_Chunk* kamehameha = 0;
Mix_Chunk* peacebitch = 0;
Mix_Chunk* getoutofmylevel = 0;
Mix_Chunk* apefight = 0;
Mix_Chunk* fuckwithme = 0;
Mix_Chunk* hitme = 0;
Mix_Chunk* fuckyouimdone = 0;
Mix_Chunk* getoutofmyface = 0;
Mix_Chunk* usetheshovel = 0;
Mix_Chunk* pyah = 0;
Mix_Chunk* sodascream = 0;
Mix_Chunk* sodamitchfight = 0;
Mix_Chunk* mitchgetmeback = 0;
Mix_Chunk* mitchfight1 = 0;
Mix_Chunk* mitchfight2 = 0;
Mix_Chunk* mitchdonewithmira = 0;
Mix_Chunk* mitchshowedupathouse = 0;
Mix_Chunk* mitchie = 0;
Mix_Chunk* earthquake = 0;
Mix_Chunk* patricklaugh = 0;
Mix_Chunk* mitchbrokenrecord = 0;
Mix_Chunk* mitchend = 0;
Mix_Chunk* notonwowsound = 0;
Mix_Chunk* oofear = 0;	
Mix_Chunk* barneydemon = 0;
Mix_Chunk* barneyletsplaydie = 0;
Mix_Chunk* barneyherewego = 0;
Mix_Chunk* barneywouldyoulike = 0;
Mix_Chunk* barneythatwasfun = 0;
Mix_Chunk* barneyheyeveryone = 0;
Mix_Chunk* barneydemon2 = 0;
Mix_Music* barneysong = 0;
Mix_Chunk* laser = 0;
Mix_Chunk* chargelaser = 0;
Mix_Chunk* cheers = 0;


//background2
void ballmove2();
//backgroun3
void ballmove3();
//background4
void ballmove4();
//------
void ballmove5(droppingobject a[]);
void ballmove6(droppingobject a[]);
void ballmove7();
void ballmove8();
void ballmove16();
void ballmove19();
void ballmove22();
bool init();
bool loadmedia();
void close();
void move();
SDL_Texture* loadtext(string s,SDL_Color textcolor);
SDL_Texture* loadtexture(string a);
SDL_Texture* loadseethrough(string a);
SDL_Texture* loadseethroughwhite(string a);
bool checkifontopof(SDL_Rect a, SDL_Rect b);
void checkifonsideofarray(rectz a[], int size, SDL_Rect heart);
void checkifontopofarray(rectz a[], int size,SDL_Rect heart);
char collisionside(SDL_Rect a, SDL_Rect b);
bool collisionsidebool(SDL_Rect a, SDL_Rect b);
bool checkifontopofcorners(SDL_Rect a, SDL_Rect b);
bool rectcollision(SDL_Rect a, SDL_Rect b);
bool rectcollisionarray(rectz a[], int size, SDL_Rect heart);
bool checkcollision(SDL_Rect a, SDL_Rect b);
void jump();

int main(int argc, char* argv[]) //input, then sprite movement, then rendering, then level switches
{
	srand(time(0));
	if (!init())
	{
		cout << "initialization failed";
	}
	else if (!loadmedia())
	{
		cout << "could not load media";
	}
	else
	{
		int counter = 2;
		bool exit = false;
		SDL_Event e;
		while (exit == false)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					exit = true;
				}
				if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_x: boshishoot = true;
					case SDLK_RETURN: boshishoot = true;
					case SDLK_w: playervely -= velocityspeed; break;
					case SDLK_a: playervelx -= velocityspeed; break;
					case SDLK_d: playervelx += velocityspeed; break;
					case SDLK_LEFT: playervelx -= velocityspeed; break;
					case SDLK_RIGHT:playervelx += velocityspeed; break;
					case SDLK_UP: playervely -= velocityspeed; break;
					}
				}
				if (e.type == SDL_KEYUP && e.key.repeat == 0)
				{

					switch (e.key.keysym.sym)
					{
					case SDLK_x: boshishoot = false;
					case SDLK_RETURN: boshishoot = false;
					case SDLK_w: playervely += velocityspeed; break;
					case SDLK_a: playervelx += velocityspeed; break;
					case SDLK_d: playervelx -= velocityspeed; break;
					case SDLK_LEFT: playervelx += velocityspeed; break;
					case SDLK_RIGHT: playervelx -= velocityspeed; break;
					case SDLK_UP: playervely += velocityspeed; break;
					}
				}
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_w && keyletgo == true || e.key.keysym.sym == SDLK_UP && keyletgo == true)
					{
						
						if (secondjump == true && keyletgo == true)
						{//3
							jumpstopglitch = true;
							jumpframes = 4;
							secondjump = false;
							keyletgo = false;
						}
					}
				}
				else if (e.type == SDL_KEYUP)
				{
					keyletgo = true;
					//cout << "true" << endl;
				}
				else if (e.type == SDL_WINDOWEVENT)
				{
					if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
					{

						screenwidth = e.window.data1;
						screenheight = e.window.data2;

					}
				}
				else if (e.type == SDL_MOUSEMOTION)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (currentsurface == textpage)
					{

					}
					else if (currentsurface == background)
					{

					}
					else if (currentsurface == background2)
					{

					}
					else if (currentsurface == background3)
					{

					}
					else if (currentsurface == background4)
					{

					}
					else if (currentsurface == background5)
					{

					}
					else if (currentsurface == background6)
					{

					}
					else if (currentsurface == background7)
					{

					}
					else if (currentsurface == background8)
					{

					}
					else if (currentsurface == background9)
					{

					}
					else if (currentsurface == background10)
					{

					}
					else if (currentsurface == background11)
					{

					}
					else if (currentsurface == background12)
					{

					}
					else if (currentsurface == background13)
					{

					}
					else if (currentsurface == background14)
					{

					}
					else if (currentsurface == background15)
					{

					}
					else if (currentsurface == background16)
					{

					}
					else if (currentsurface == background17)
					{

					}
					else if (currentsurface == background18)
					{

					}
					else if (currentsurface == background19)
					{

					}
					else if (currentsurface == background20)
					{

					}
					else if (currentsurface == background21)
					{

					}
					else if (currentsurface == background22)
					{

					}
					else if (currentsurface == background23)
					{

					}
					else if (currentsurface == background24)
					{

					}
					else if (currentsurface == background25)
					{

					}
					else if (currentsurface == background26)
					{

					}
					else if (currentsurface == safespacemenu)
					{

					}
					else
					{
						if (x < 700 && x>385 && y < 625 && y>465)
						{
							currentsurface = menu2;
						}
						else
						{
							currentsurface = menu1;
						}
					}

				}
				else if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (currentsurface == safespacemenu || currentsurface == background || currentsurface == background2 || currentsurface == background3 || currentsurface == background4 || currentsurface == background5 || currentsurface == background6 || currentsurface == background7 || currentsurface == background8 || currentsurface == background9 || currentsurface == background10 || currentsurface == background11 || currentsurface == background12 || currentsurface == background13 || currentsurface == background14 || currentsurface == background15 || currentsurface == background16 || currentsurface == background17 || currentsurface == background18 || currentsurface == background19 || currentsurface == background20 || currentsurface == background21 || currentsurface == background22 || currentsurface == background23 || currentsurface == background24 || currentsurface == background25 || currentsurface == background26)
					{

					}
					else if (currentsurface == textpage)
					{
						if (x > 490 && x < 570 && y < 526 && y>495)
						{
							currentsurface = background;
						}

					}
					else
					{
						if (x < 700 && x>385 && y < 625 && y>465)
						{
							currentsurface = textpage;
						}
					}
				}

			}
			move();
			
			
			if (currentsurface == background2)
			{
				ballmove2();
			}
			else if (currentsurface == background3)
			{
				ballmove3();
			}
			else if (currentsurface == background4)
			{
				ballmove4();
			}
			else if (currentsurface == background5)
			{
				
			}
			else if (currentsurface == background6)
			{
				
			}
			else if (currentsurface == background7)
			{

			}
			else if (currentsurface == background8)
			{

			}
			else if (currentsurface == background9)
			{

			}
			else if (currentsurface == background10)
			{

			}
			else if (currentsurface == background11)
			{

			}
			else if (currentsurface == background12)
			{

			}
			else if (currentsurface == background13)
			{

			}
			else if (currentsurface == background14)
			{

			}
			else if (currentsurface == background15)
			{

			}
			else if (currentsurface == background16)
			{

			}
			
			SDL_Rect rectback = { 0,0,1200,91 };
			SDL_Rect rectnext = { 500,500,69,29 };
			SDL_Rect rectx = { 0,0,screenwidth,screenheight };

			if (heartcount >= 40)
			{
				heartcount = 0;
			}
			if ((heartcount / 10) == 0)
			{
				currentheart = heart1;
			}
			if ((heartcount / 10) == 1)
			{
				currentheart = heart2;
			}
			if ((heartcount / 10) == 2)
			{
				currentheart = heart1;
			}
			if ((heartcount / 10) == 3)
			{
				currentheart = heart3;
			}
		
			
			SDL_RenderClear(grender);
			if (currentsurface == safespacemenu)
			{
				SDL_RenderCopy(grender, whitebackground, 0, 0);
				SDL_RenderCopy(grender, safespacetext, 0, &rectback);
				if (safespacecounter > 500)
				{
					currentsurface = menu1;
				}
				safespacecounter++;
			}
			else if (currentsurface == menu1 || currentsurface == menu2)
			{
				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(titlesong, -1);
				}
				SDL_RenderCopy(grender, currentsurface, 0, 0);
			}
			else if (currentsurface == textpage)
			{		
				Mix_HaltMusic();
				SDL_RenderCopy(grender, currentsurface, 0, &rectback);
				SDL_RenderCopy(grender, nextz, 0, &rectnext);
			}
			else if (currentsurface == background)
			{
				if (playerx < 0)
				{
					playerx -= playervelx;
				}
				if (onetime == false)
				{
					//Mix_PlayMusic(barneytheme, 0);
					//Mix_PlayChannel(-1, pokigasm, 0);
				}
				/*Mix_ResumeMusic();
				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(barneytheme, -1);
				}*/

				onetime = true;
				
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect instructionrect = { 500,50,568,29};
				SDL_Rect kid = { 850,350,146,237 };
				SDL_Rect barneytalkz = { 800,300,350,29 };
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, yellowbarney, 0, &kid);
				SDL_RenderCopy(grender, instructions, 0, &instructionrect);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				
				SDL_RenderCopy(grender, barneytalk, 0, &barneytalkz);
			
			}
			else if (currentsurface == background2)
			{

				SDL_Rect ballrect1 = { ball1x,ball1y,20,20 };
				SDL_Rect ballrect11 = { ball11x,ball11y,20,20 };
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, ball1, 0, &ballrect1);
				SDL_RenderCopy(grender, ball1, 0, &ballrect11);
				gameover = checkcollision(ballrect1, heartman);
				if (currentkeystatereset[SDL_SCANCODE_Q])
				{
					gameover = 1;
				}
				if (gameover == 1)
				{
					playerx = 0;

				}
				gameover = checkcollision(ballrect11, heartman);
				if (gameover == 1)
				{
					playerx = 0;
					
				}
			}
			else if (currentsurface == background3)
			{
				SDL_Rect ballrect2 = { ball2x,ball2y,20,20 };
				SDL_Rect ballrect3 = { ball3x,ball3y,20,20 };
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, ball2, 0, &ballrect2);
				SDL_RenderCopy(grender, ball3, 0, &ballrect3);
				gameover = checkcollision(ballrect2, heartman);
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					gameover = 1;
				}
				if (gameover == 1)
				{
					playerx = 0;
					
				}
				
				gameover = checkcollision(ballrect3, heartman);
				if (gameover == 1)
				{
					playerx = 0;
					
				}
			}
			else if (currentsurface == background4)
			{

				
				SDL_Rect ballz = { ball4x,ball4y,20,20 };
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect tryhard = { tryhardx,tryhardy,200,400 };
				SDL_Rect chicken = { 440,chickeny,270,225 };
				SDL_Rect plat1 = { 250,450,200,20 };
				SDL_Rect plat2 = { 650,350,350,20 };//585 250
				SDL_Rect plat3 = { 40,300,200,20 };
				SDL_Rect plat4 = { 250,150,600,20 };
				SDL_Rect spike1 = { 400,100,50,50 };
				SDL_Rect spike11 = { 550,100,50,50 };
				SDL_Rect spike111 = { 700,100,50,50 };
				SDL_Rect spike5 = { 610,515,50,75 };
				SDL_Rect spike2 = { 460,515,50,75 };//bottoms ones 2-4
				SDL_Rect spike3 = { 510,515,50,75 };
				SDL_Rect spike4 = { 560,515,50,75 };
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, ball2, 0, &ballz);
				SDL_RenderCopy(grender, spike, 0, &spike1);
				SDL_RenderCopy(grender, spike, 0, &spike11);
				SDL_RenderCopy(grender, spike, 0, &spike111);
				SDL_RenderCopy(grender, spike, 0, &spike5);
				SDL_RenderCopy(grender, spike, 0, &spike2);
				SDL_RenderCopy(grender, spike, 0, &spike3);
				SDL_RenderCopy(grender, spike, 0, &spike4);
				SDL_RenderCopy(grender, friedchicken, 0, &chicken);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderFillRect(grender, &plat1);
				SDL_RenderFillRect(grender, &plat2);
				SDL_RenderFillRect(grender, &plat3);
				SDL_RenderFillRect(grender, &plat4);
				//SDL_RenderFillRect(grender, &ground);
				
				if (tryhardspawn == true)
				{
					SDL_RenderCopy(grender, TryHard, 0, &tryhard);
				}
				//check if platform changed
				/*if (checkifontopof(heartman, ground))
				{
					cout << "it works";
					platform = 5;
					int plat1y = 550;
				}*/
				if (checkifontopof(heartman, plat1))
				{
					platform = 1;
					int plat1y = 400;
				}
				if (checkifontopof(heartman, plat2))
				{
					platform = 2;
					int plat2y = 320;
				}
				if (checkifontopof(heartman, plat3))
				{
					platform = 3;
					int plat3y = 225;
				}
				if (checkifontopof(heartman, plat4))
				{
					platform = 4;
					int plat4y = 75;
				}
				else if (playery == 488)
				{
					platform = 5;
					
				}
				if (platform != pastplatform)
				{
					platchange = true;
				}

				//-----check if platform is higher or lower
				if (pastplatform == 1)
				{
					pastplaty = 400;
				}
				else if (pastplatform == 2)
				{
					pastplaty = 320;
				}
				else if (pastplatform == 3)
				{
					pastplaty = 225;
				}
				else if (pastplatform == 4)
				{
					pastplaty = 75;
				}
				else if (pastplatform == 5)
				{
					pastplaty = 550;
				}
				if (platform == 1)
				{
					currentplaty = 400;
				}
				else if (platform == 2)
				{
					currentplaty = 320;
				}
				else if (platform == 3)
				{
					currentplaty = 225;
				}
				else if (platform == 4)
				{
					currentplaty = 75;
				}
				else if (platform == 5)
				{
					currentplaty = 585;
				}
				if (pastplaty - currentplaty > 1)
				{
					tohigherplat = true;
				}
				pastplatform = platform;
				/*
				pastypositioncounter++;
				if (pastypositioncounter > 200)
				{
					pastyposition = playery;
					pastypositioncounter = 0;
				}
				
				if (pastyposition <= playery)
				{
					goingdown = true;
				}
				else
				{
					goingdown = false;
				}
				cout << goingdown;*/
				//this is for triple jump glitch, pauses you for a second, also for top to stop gravity
				if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4))
				{
					
					playery -= gravityspeed;
					if (jumpstopglitch == true && tohigherplat == true)
					{
						
						jumpcount = 0;
						jumpagain = false; 
						secondjump = false;
						jumpstopglitch = false;
						platchange = false;
						tohigherplat = false;
					}
					jumpcount++;
					if (jumpcount > 8)
					{
						jumpagain = true;
						secondjump = false;
					}
			
					
				}
				//for hit detection move back, unless of platform
				if (rectcollision(heartman, plat1) || rectcollision(heartman, plat2) || rectcollision(heartman, plat3) || rectcollision(heartman, plat4))
				{
					
					playerx -= playervelx;
				
					if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4))
					{
						playerx += playervelx;
					}
					else //this is for side glitch
					{
						if (collisionside(heartman,plat1) == 'l' && playerpos == 'a' || collisionside(heartman, plat2) == 'l' && playerpos == 'a' || collisionside(heartman, plat3) == 'l' && playerpos == 'a' || collisionside(heartman, plat4) == 'l' && playerpos == 'a')
						{
							
							playerx += playervelx;
						}
						if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat2) == 'r' && playerpos == 'd' || collisionside(heartman, plat3) == 'r' && playerpos == 'd' || collisionside(heartman, plat4) == 'r' && playerpos == 'd')
						{
							playerx += playervelx;
						}
					}
					/*if (playerpos == 'w')
					{
						jumpframes = 0;
					}*/
					jumpframes = 0;
				}
				
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, tryhard) || rectcollision(heartman, spike1) || rectcollision(heartman, spike2) || rectcollision(heartman, spike3) || rectcollision(heartman, spike4) || rectcollision(heartman, spike11) || rectcollision(heartman, spike111) || rectcollision(heartman,ballz))
				{
					playerx = 0;
					//tryhardreset = true;
				}
				
			}
			else if (currentsurface == background5)
			{
				
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect plat1 = { 450,230,20,370 };
				SDL_Rect plat2 = { 0,410,250,50 };
				SDL_Rect plat3 = { 150,230,500,20 };
				SDL_Rect plat4 = { 0,0,1300,20 }; //roof
				SDL_Rect plat5 = { 850,0,20,450 };
				SDL_Rect plat6 = { 570,430,280,20 };
				SDL_Rect plat7 = { 1180,100,20,350 };
				SDL_Rect trapwall1 = { 850,450,20,135 };
				SDL_Rect trapwall2 = { 1180,450,20,trapwall2y };
				SDL_Rect spike1 = { 400,550,50,50 };
				SDL_Rect spike2 = { 255,410,40,50 };
				SDL_Rect spike3 = { 250,20,32,32 }; //up spike
				SDL_Rect spike4 = { 250,200,32,32 }; //down spike
				SDL_Rect spike5 = { 430,180,50,50 };
				SDL_Rect spike6 = { 600,180,50,50 };
				SDL_Rect spike7 = { 700,20,50,50 };//roof
				SDL_Rect spike8 = { 800,20,50,50 };//roof
				SDL_Rect spike9 = { 790,225,50,75 };
				SDL_Rect spike10 = { 670,380,50,50 };
				SDL_Rect spike11 = { 470,550,50,50 };
				SDL_Rect yellowbarney = {yellowbarneyx,40,50,50 };
				rectz rectzz[6];
				droppingobject dropobjects[15];
				if (onetime5 == true)
				{
					for (int i = 0; i < 15; i++)
					{
						dropobjects[i].texture = blooddrop;
						dropobjects[i].rect.h = 50;
						dropobjects[i].rect.w = 50;
						dropobjects[i].rect.y = 20;
						dropobjects[i].rect.x = (rand() % 200) + 900;
					}
					onetime5 = false;
				}
				dropobjects[12].texture = kid1;
				dropobjects[13].texture = kid2;
				dropobjects[14].texture = kid3;
				rectzz[0].plat = plat1; rectzz[1].plat = plat2; rectzz[2].plat = plat3; rectzz[3].plat = plat4; rectzz[4].plat = plat5; rectzz[5].plat = plat6;
				SDL_RenderClear(grender);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, spike, 0, &spike1);
				SDL_RenderCopyEx(grender, spike, 0, &spike2, 90, NULL, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike3, 180, NULL, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, spike, 0, &spike4);
				SDL_RenderCopy(grender, spike, 0, &spike5);
				SDL_RenderCopy(grender, spike, 0, &spike6);
				SDL_RenderCopyEx(grender, spike, 0, &spike7, 180, NULL, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike8, 180, NULL, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike9, 270, NULL, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, spike, 0, &spike10);
				SDL_RenderCopy(grender, spike, 0, &spike11);
				SDL_RenderCopy(grender, yellowbarneyevil, 0, &yellowbarney);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 0);
				SDL_RenderFillRect(grender, &plat1);
				SDL_RenderFillRect(grender, &plat2);
				SDL_RenderFillRect(grender, &plat3);
				SDL_RenderFillRect(grender, &plat4);
				SDL_RenderFillRect(grender, &plat5);
				SDL_RenderFillRect(grender, &plat6);
				SDL_RenderFillRect(grender, &plat7);
				SDL_SetRenderDrawColor(grender, 255, 255, 255, 255);
				
				if (playerx == 900)
				{
					trap5 = true;
				}
				if (trap5 == true)
				{
					ballmove5(dropobjects);
					SDL_RenderFillRect(grender, &trapwall1);
					SDL_RenderFillRect(grender, &trapwall2);
					if (rectcollision(heartman, trapwall1) || rectcollision(heartman, trapwall2))
					{
						playerx -= playervelx;
					}
					
					if (yellowbarneyx == 1150 && yellowbarneyfirst == true)
					{
						
					}
					else if (yellowbarneyfirst == false)
					{
						yellowbarneyx++;
						if (trapwall2y == 0)
						{

						}
						else
						{
							trapwall2y--;
						}

					}
					else
					{
						Mix_PlayChannel(-1, barneyroar, 0);
						Mix_PlayChannel(0, oof, 0);
						yellowbarneyx--;
					}
				}
				if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat5) || checkifontopof(heartman, plat6) || checkifontopof(heartman, plat7))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}
				
				if (rectcollision(heartman, plat1) || rectcollision(heartman, plat2) || rectcollision(heartman, plat3) || rectcollision(heartman, plat4) || rectcollision(heartman, plat5) || rectcollision(heartman, plat6) || rectcollision(heartman, plat7))
				{
				
					playerx -= playervelx;
					
					if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat5) || checkifontopof(heartman, plat6) || checkifontopof(heartman, plat7))
					{
						//cout << "ontop";
						playerx += playervelx;
						//if hitting something else than itself while on top of move back
						//helps stop going through wall when on top of something
						checkifontopofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, plat1) == 'l' && playerpos == 'a' || collisionside(heartman, plat2) == 'l' && playerpos == 'a' || collisionside(heartman, plat3) == 'l' && playerpos == 'a' || collisionside(heartman, plat4) == 'l' && playerpos == 'a' || collisionside(heartman, plat5) == 'l' && playerpos == 'a' || collisionside(heartman, plat6) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat2) == 'r' && playerpos == 'd' || collisionside(heartman, plat3) == 'r' && playerpos == 'd' || collisionside(heartman, plat4) == 'r' && playerpos == 'd' || collisionside(heartman, plat5) == 'r' && playerpos == 'd' || collisionside(heartman, plat6) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, plat1) || collisionsidebool(heartman, plat2) || collisionsidebool(heartman, plat3) || collisionsidebool(heartman, plat4) || collisionsidebool(heartman, plat5) || collisionsidebool(heartman, plat6))
					{
						
					}
					else
					{
						jumpframes = 0;
					}
					
					/*if (playerpos == 'w')
					{
						jumpframes = 0;
					}*/
					
					/*if (collisionside(heartman, plat5) == 'l' && playerpos == 'd' || collisionside(heartman, plat5) == 'l' && playerpos == 'w')
					{
						
						cout << "hey";
					}
					else if (collisionside(heartman, plat5) == 'r' && playerpos == 'd' || collisionside(heartman, plat5) == 'r' && playerpos == 'w')
					{

					}
					else if (collisionside(heartman, plat1) == 'l' && playerpos == 'd' || collisionside(heartman, plat1) == 'l' && playerpos == 'w')
					{

						cout << "hey";
					}
					else if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat1) == 'r' && playerpos == 'w')
					{

					}
					else
					{
						jumpframes = 0; //fixes jump through wall glitch I think because when you go up and right it doesnt work before
					}*/
		
				}

				if (currentkeystatereset[SDL_SCANCODE_Q] == 1||rectcollision(heartman, spike1) || rectcollision(heartman, spike2) || rectcollision(heartman, spike3) || rectcollision(heartman, spike4) || rectcollision(heartman, spike5) || rectcollision(heartman, spike6) || rectcollision(heartman, spike7) || rectcollision(heartman, spike8) || rectcollision(heartman, spike9) || rectcollision(heartman, spike10) || rectcollision(heartman, spike11))
				{
					playerx = 0;
					playery = 500;
					onetime5 = true;
					trap5 = false;
					blooddropcounter = 0;
					yellowbarneyx = 1200;
					Mix_HaltChannel(-1);
					for (int i = 0; i < 15; i++)
					{
						dropobjects[i].rect = { 0,0,0,0 };
						dropobjects[i].texture = 0;
					}
					//tryhardreset = true;
				}
				for (int i = 0; i < 15; i++)
				{
					if (rectcollision(heartman, dropobjects[i].rect))
					{
						playerx = 0;
						playery = 500;
						onetime5 = true;
						trap5 = false;
						Mix_HaltChannel(-1);
						yellowbarneyx = 1200;
						blooddropcounter = 0;
						for (int i = 0; i < 15; i++)
						{
							dropobjects[i].rect = { 0,0,0,0 };
							dropobjects[i].texture = 0;
						}
					}
				}


			}
			else if (currentsurface == background6)
			{
				SDL_Rect yellowbarney = { yellowbarneyx6,60,50,50 };
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect bar1 = { 0,585,120,140 };
				SDL_Rect bar2 = { 120,520,100,180 };
				SDL_Rect bar3 = { 220,480,100,220 };
				SDL_Rect bar4 = { 320,440,100,260 };
				SDL_Rect bar5 = { 420,400,100,300 };
				SDL_Rect bar6 = { 520,400,100,340 };
				SDL_Rect bar7 = { 620,440,100,380 };
				SDL_Rect bar8 = { 720,480,100,420 };
				SDL_Rect bar9 = { 820,520,100,460 };
				SDL_Rect bar10 = { 920,585,100,500 };
				SDL_Rect bar11 = { 1020,585,100,540 };
				SDL_Rect bar12 = { 1120,120,100,580 };
				SDL_Rect Ladder = { 1100,120,20,430 };
				SDL_Point a[2];
				a[0] = { 80, 600 };
				a[1] = { 1100,100 };
				rectz rectzz[12];
				rectzz[0].plat = bar1; rectzz[1].plat = bar2; rectzz[2].plat = bar3; rectzz[3].plat = bar4; rectzz[4].plat = bar5; rectzz[5].plat = bar6; rectzz[6].plat = bar7; rectzz[7].plat = bar8; rectzz[8].plat = bar9; rectzz[9].plat = bar10; rectzz[10].plat = bar11; rectzz[11].plat = bar12;
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, yellowbarneyevil, 0, &yellowbarney);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 0);
				SDL_RenderFillRect(grender, &bar1);
				SDL_RenderFillRect(grender, &bar2);
				SDL_RenderFillRect(grender, &bar3);
				SDL_RenderFillRect(grender, &bar4);
				SDL_RenderFillRect(grender, &bar5);
				SDL_RenderFillRect(grender, &bar6);
				SDL_RenderFillRect(grender, &bar7);
				SDL_RenderFillRect(grender, &bar8);
				SDL_RenderFillRect(grender, &bar9);
				SDL_RenderFillRect(grender, &bar10);
				SDL_RenderFillRect(grender, &bar11);
				SDL_RenderFillRect(grender, &bar12);
				SDL_RenderCopy(grender, ladder, 0, &Ladder);
				droppingobject dropobjects[9];
				//SDL_RenderDrawLines(grender, a,2);
				//SDL_RenderDrawLine(grender, 1100, 100, 1200, 100);
				if (checkifontopof(heartman, bar1) || checkifontopof(heartman, bar2) || checkifontopof(heartman, bar3) || checkifontopof(heartman, bar4) || checkifontopof(heartman, bar5) || checkifontopof(heartman, bar6) || checkifontopof(heartman, bar7) || checkifontopof(heartman, bar8) || checkifontopof(heartman, bar9) || checkifontopof(heartman, bar10) || checkifontopof(heartman, bar11) || checkifontopof(heartman, bar12) || checkifontopof(heartman, Ladder))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}
				if (collisionside(heartman, Ladder) == 'l')
				{
					ladderon = true;
					//playery -= gravityspeed;
					
				}
				
				if (checkcollision(heartman, bar1) || checkcollision(heartman, bar2) || checkcollision(heartman, bar3) || checkcollision(heartman, bar4) || checkcollision(heartman, bar5) || checkcollision(heartman, bar6) || checkcollision(heartman, bar7) || checkcollision(heartman, bar8) || checkcollision(heartman, bar9) || checkcollision(heartman, bar10) || checkcollision(heartman, bar11) || checkcollision(heartman, bar12))
				{
					//cout << "sup";
					playerx -= playervelx;

					if (checkifontopof(heartman, bar1) || checkifontopof(heartman, bar2) || checkifontopof(heartman, bar3) || checkifontopof(heartman, bar4) || checkifontopof(heartman, bar5) || checkifontopof(heartman, bar6) || checkifontopof(heartman, bar7) || checkifontopof(heartman, bar8) || checkifontopof(heartman, bar9) || checkifontopof(heartman, bar10) || checkifontopof(heartman, bar11) || checkifontopof(heartman, bar12))
					{
						
						playerx += playervelx;
						checkifontopofarray(rectzz, 12, heartman);
						if (rectcollisionarray(rectzz, 12, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 12; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, bar1) == 'l' && playerpos == 'a' || collisionside(heartman, bar2) == 'l' && playerpos == 'a' || collisionside(heartman, bar3) == 'l' && playerpos == 'a' || collisionside(heartman,bar4) == 'l' && playerpos == 'a' || collisionside(heartman,bar5) == 'l' && playerpos == 'a' || collisionside(heartman, bar6) == 'l' && playerpos == 'a' || collisionside(heartman, bar7) == 'l' && playerpos == 'a' || collisionside(heartman, bar8) == 'l' && playerpos == 'a' || collisionside(heartman, bar9) == 'l' && playerpos == 'a' || collisionside(heartman, bar10) == 'l' && playerpos == 'a' || collisionside(heartman, bar11) == 'l' && playerpos == 'a' || collisionside(heartman, bar12) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, bar1) == 'r' && playerpos == 'd' || collisionside(heartman, bar2) == 'r' && playerpos == 'd' || collisionside(heartman, bar3) == 'r' && playerpos == 'd' || collisionside(heartman, bar4) == 'r' && playerpos == 'd' || collisionside(heartman, bar5) == 'r' && playerpos == 'd' || collisionside(heartman, bar6) == 'r' && playerpos == 'd' || collisionside(heartman, bar7) == 'r' && playerpos == 'd' || collisionside(heartman, bar8) == 'r' && playerpos == 'd' || collisionside(heartman, bar9) == 'r' && playerpos == 'd' || collisionside(heartman, bar10) == 'r' && playerpos == 'd' || collisionside(heartman, bar11) == 'r' && playerpos == 'd' || collisionside(heartman, bar12) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					//makes it so i can slide down sides
					if (collisionsidebool(heartman, bar1) || collisionsidebool(heartman, bar2) || collisionsidebool(heartman, bar3) || collisionsidebool(heartman, bar4) || collisionsidebool(heartman, bar5) || collisionsidebool(heartman, bar6) || collisionsidebool(heartman, bar7) || collisionsidebool(heartman, bar8) || collisionsidebool(heartman, bar9) || collisionsidebool(heartman, bar10) || collisionsidebool(heartman, bar11) || collisionsidebool(heartman, bar12))
					{

					}
					else
					{
						jumpframes = 0;
					}	
				}
				
				
				if (onetime6 == true)
				{
					for (int i = 0; i < 9; i++)
					{
						dropobjects[i].texture = blooddrop;
						dropobjects[i].rect.h = 50;
						dropobjects[i].rect.w = 50;
						dropobjects[i].rect.y = 20;
						dropobjects[i].rect.x = (rand() % 800) + 100;
					}
					onetime6 = false;
				}
				ballmove6(dropobjects);
				if (yellowbarneyfirst6 == true)
				{
					if (yellowbarneyx6 == 1180)
					{
						Mix_PlayChannel(-1, barneyroar, 0);
					}
					if (yellowbarneyx6 == 1080)
					{
						
						yellowbarneyfirst6 = false;
					}
					if(yellowbarneyx6 != 1080)
					{
						yellowbarneyx6--;
					}
					
				}
				
				if (goback6 > 400)
				{
					yellowbarneyx6++;
				}
				goback6++;
				for (int i = 0; i < 9; i++)
				{
					if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, dropobjects[i].rect) || rectcollision(heartman, yellowbarney))
					{
						playerx = 0;
						playery = 500;
						//yellowbarneyx6 = 1200;
						//goback6 = 0;
						//Mix_HaltChannel(-1);
						//yellowbarneyfirst6 = true;
					}
				}
			}
			else if (currentsurface == background7)
			{
				//SDL_Texture* spinning = SDL_CreateTexture(grender, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 200);
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect tryhardz = { tryhard7x,tryhard77y,100,200 };
				SDL_Rect jailwall = { 800,420,20,200 };
				SDL_Rect whitewall = { 100,20,20,150 };
				SDL_Rect plat1 = { 0,170,1000,20 };
				SDL_Rect plat1roof = { 0,0,1200,20 };
				SDL_Rect plat2 = { 0,170,20,430 };
				SDL_Rect plat3 = { 1180,0,20,420 };
				SDL_Rect plat4 = { 200,400,1000,20 };
				SDL_Rect wall = { 480,0,20,80 };
				SDL_Rect block = { 0,0,20,300 };
				SDL_Rect ballz1 = { ball71x, ball71y,20,20 };
				SDL_Rect ballz2 = { ball72x,ball72y,20,20 };
				SDL_Rect spike1 = { 1000,155,30,50 };
				SDL_Rect spike2 = { 1025,350,50,50 };
				SDL_Rect spike3 = { 875,350,50,50 };
				SDL_Rect spike4 = { 725,350,50,50 };
				SDL_Rect spike5 = { 575,350,50,50 };
				SDL_Rect spike6 = { 250,380,50,20 };
				SDL_Rect spike7 = { 300,380,50,20 };
				SDL_Rect spike8 = { 350,380,50,20 };
				SDL_Rect spike9 = { 400,190,50,20 };
				SDL_Rect spike10 = { 200,190,50,20 };
				SDL_Rect spin1 = {300,525,200,10};
				SDL_Rect spin2 = {};
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 0);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderFillRect(grender, &plat1);
				SDL_RenderFillRect(grender, &plat1roof);
				SDL_RenderFillRect(grender, &plat2);
				SDL_RenderFillRect(grender, &plat3);
				SDL_RenderFillRect(grender, &plat4);
				SDL_RenderFillRect(grender, &wall);
				SDL_RenderCopyEx(grender, spike, 0, &spike1, 90, NULL, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike9, 180, NULL, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike10, 180, NULL, SDL_FLIP_NONE);
				if (jailwall7 == true)
				{
					SDL_SetRenderDrawColor(grender, 255, 255, 255, 0);
					SDL_RenderFillRect(grender, &jailwall);
					if (checkcollision(heartman, jailwall))
					{
						playerx -= playervelx;
					}
				}
				SDL_RenderCopy(grender, spike, 0, &spike2);
				SDL_RenderCopy(grender, spike, 0, &spike3);
				SDL_RenderCopy(grender, spike, 0, &spike4);
				SDL_RenderCopy(grender, spike, 0, &spike5);
				SDL_RenderCopy(grender, spike, 0, &spike6);
				SDL_RenderCopy(grender, spike, 0, &spike7);
				SDL_RenderCopy(grender, spike, 0, &spike8);
				//SDL_RenderCopyEx(grender, spinning, 0, &spin1,spinangle,NULL,SDL_FLIP_NONE);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
		
			
				SDL_RenderCopy(grender, ball1, 0, &ballz1);
				SDL_RenderCopy(grender, ball2, 0, &ballz2);
				rectz rectzz[7];
				rectzz[0].plat = plat1; rectzz[1].plat = plat2; rectzz[2].plat = plat3; rectzz[3].plat = plat4; rectzz[4].plat = plat1roof; rectzz[5].plat = wall;  rectzz[5].plat = spin1;
				ballmove7();

				if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat1roof) || checkifontopof(heartman, wall) || checkifontopof(heartman, block))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, plat1) || checkcollision(heartman, plat2) || checkcollision(heartman, plat3) || checkcollision(heartman, plat4) || checkcollision(heartman, plat1roof) || checkcollision(heartman, wall) || checkcollision(heartman, block))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat1roof) || checkifontopof(heartman, wall) || checkifontopof(heartman, block))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, plat1) == 'l' && playerpos == 'a' || collisionside(heartman, plat2) == 'l' && playerpos == 'a' || collisionside(heartman, plat3) == 'l' && playerpos == 'a' || collisionside(heartman, plat4) == 'l' && playerpos == 'a' || collisionside(heartman, plat1roof) == 'l' && playerpos == 'a' || collisionside(heartman, wall) == 'l' && playerpos == 'a' || collisionside(heartman, block) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat2) == 'r' && playerpos == 'd' || collisionside(heartman, plat3) == 'r' && playerpos == 'd' || collisionside(heartman, plat4) == 'r' && playerpos == 'd' || collisionside(heartman, plat1roof) == 'r' && playerpos == 'd' || collisionside(heartman, wall) == 'r' && playerpos == 'd' || collisionside(heartman, block) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, plat1) || collisionsidebool(heartman, plat2) || collisionsidebool(heartman, plat3) || collisionsidebool(heartman, plat4) || collisionsidebool(heartman, plat1roof) || collisionsidebool(heartman, wall) || collisionsidebool(heartman, block))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				//beggining
				if (beggining7 == true)
				{
					if (chicken7y >= 130)
					{
						dontrenderwhite7 = true;
						SDL_RenderFillRect(grender, &block);
					}
					
					SDL_Rect yellowbarney = { yellowbarney7x,100,50,50 };
					SDL_Rect chickenz = { chicken7x,chicken7y,40,40 };
					SDL_Rect tryhardz = { 400,tryhard7y,200,400 };
					SDL_SetRenderDrawColor(grender, 255, 255, 255, 0);
					if (dontrenderwhite7 == false)
					{
						SDL_RenderFillRect(grender, &whitewall);
						if (checkcollision(heartman, whitewall))
						{
							playerx -= playervelx;
						}

					}
					if (tryhard7y < -450)
					{

					}
					else
					{
						if (tryhard7y < 0)
						{
							Mix_PlayChannel(-1, scream, 0);
							if (chicken7y >= 130)
							{
								dontrenderwhite7 = true;
							}
							else
							{
								chicken7y++;
							}

						}
						else
						{
							SDL_RenderCopy(grender, yellowbarneyevil, 0, &yellowbarney);
						}
					}
					SDL_RenderCopy(grender, friedchicken, 0, &chickenz);
					SDL_RenderCopy(grender, TryHard, 0, &tryhardz);
					if (yellowbarney7x > 285)
					{
						tryhard7y -= 15;
						
					}
					if (yellowbarney7x > 425)
					{

					}
					else
					{
						yellowbarney7x += 3;
						chicken7x += 3;
					}


				}
				//chicken
				if (playerx == 430 && playery <100)
				{
					chickengrab = true;
					tryhard7x = -200;
					tryhard77y = 0;
				}
				if (chickengrab == true)
				{
					chicken7x = playerx + 50;
					chicken7y = playery;
					//tryhard movement
				
					SDL_RenderCopy(grender, TryHard, 0, &tryhardz);
					if (tryhard7x < 1000 && tryhard77y == 0)
					{
						tryhard7x += 5;
					}
					if (tryhard7x >= 1000 && tryhard77y <= 200)
					{
						tryhard77y += 5;
					}
					if (tryhard7x >= 50 && tryhard77y == 200)
					{
						tryhard7x -= 5;
					}
					if (tryhard7x == 50 && tryhard77y <= 400 && tryhard77y >= 200)
					{
						tryhard77y += 5;
					}
					if (tryhard7x <= 700 && tryhard77y == 400)
					{
						tryhard7x += 5;
					}
				}

				//trihard stuff
				if (playery > 420 && playerx > 800)
				{
					shoottrihards = false;
					jailwall7 = true;
					for (int i = 0; i < 10; i++)
					{
						trihards[i].rect = { 0,0,0,0 };
					}
					
				}
				if (playery > 420 && onetime7 == true)
				{
					shoottrihards = true;
				
				}
				if (shoottrihards == true && onetime7 == true)
				{
					for (int i = 0; i < 10; i++)
					{
						int x = rand() % 2;
						trihards[i].texture = TryHard;
						if (x == 0)
						{
							trihards[i].rect = { 1200,425,35,35 };
						}
						if (x == 1)
						{
							trihards[i].rect = { 1200,550,35,35 };
						}
						
					}
					onetime7 = false;
				}
				//hit enemies
				for (int i = 0; i < 10; i++)
				{
					if (rectcollision(heartman, trihards[i].rect))
					{
						playerx = 0;
						playery = 50;
						chickengrab = false;
						chicken7x = 475;
						chicken7y = 130;
						shoottrihards = false;
						tryhard7x = -200;
						onetime7 = true;
					}
				}
				if(currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, spike1) || rectcollision(heartman, spike2) || rectcollision(heartman, spike3) || rectcollision(heartman, spike4) || rectcollision(heartman, spike5)|| rectcollision(heartman, spike6) || rectcollision(heartman, spike7) || rectcollision(heartman, spike8) || rectcollision(heartman, spike9) || rectcollision(heartman, spike10) || rectcollision(heartman, ballz2) || rectcollision(heartman, ballz1) || rectcollision(heartman, tryhardz))
				{
					tryhard7x = -200;
					playerx = 0;
					playery = 50;
					chickengrab = false;
					chicken7x = 475;
					chicken7y = 130;
					shoottrihards = false;
					onetime7 = true;
				}
				

				
			}
			else if (currentsurface == background8)
			{
				SDL_Rect twitchz = { twitch8x, twitch8y, 100, 200 };
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect chicken = { playerx+50,playery,40,40 };
				SDL_Rect trihardd = { trihard8x, trihard8y,trihard8w,trihard8h };
				SDL_Rect box = { 1050,box8y,50,10 };
				SDL_Rect plat1 = { 200,170,1000,20 };
				SDL_Rect plat1roof = { 0,0,1200,5 };
				SDL_Rect plat2 = { 1180,170,20,430 };
				SDL_Rect plat3 = { 0,0,20,420 };
				SDL_Rect plat4 = { 0,400,1000,20 };
				SDL_Rect ballz1 = { ball81x,ball81y,50,50 };
				SDL_Rect ballz2 = { ball82x,ball82y,50,50 };
				SDL_Rect ballz3 = { ball83x,ball83y,50,50 };
				SDL_Rect smorcz = { 1130,smorc8y,50,50 };
				SDL_Rect sjw = { sjw81x,sjw81y,50,50 };
				SDL_Rect sjw2 = { sjw82x,350,50,50 };
				SDL_Rect penguinz = { 20,325,75,75 };
				SDL_Rect wall1 = { 300,5,20,165 };
				SDL_Rect wall2 = { 500,5,20,165 };
				SDL_Rect wall3 = { 700,5,20,165 };
				SDL_Rect wall4 = { 900,5,20,165 };
				SDL_Rect wall5 = { wall85x,wall85y,20,150 };


				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderFillRect(grender, &plat1);
				SDL_RenderFillRect(grender, &plat1roof);
				SDL_RenderFillRect(grender, &plat2);
				SDL_RenderFillRect(grender, &plat3);
				SDL_RenderFillRect(grender, &plat4);
				SDL_SetRenderDrawColor(grender, 148, 0, 211, 255);
				SDL_RenderFillRect(grender, &box);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, fourhead, 0, &ballz1);
				SDL_RenderCopy(grender, opopie, 0, &ballz2);
				SDL_RenderCopy(grender, dorito, 0, &ballz3);
				SDL_RenderCopy(grender, smorc, 0, &smorcz);
				SDL_RenderCopy(grender, hotpokket, 0, &sjw);
				SDL_RenderCopyEx(grender, hotpokket, 0, &sjw2, sjw82angle, NULL, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, penguin, 0, &penguinz);
				if (wall1red == true)
				{
					SDL_SetRenderDrawColor(grender, 255, 0, 0, 255);
				}
				SDL_RenderFillRect(grender, &wall1);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				if (wall2red == true)
				{
					SDL_SetRenderDrawColor(grender, 255, 0, 0, 255);
				}
				SDL_RenderFillRect(grender, &wall2);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				if (wall3red == true)
				{
					SDL_SetRenderDrawColor(grender, 255, 0, 0, 255);
				}
				SDL_RenderFillRect(grender, &wall3);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				if (wall4red == true)
				{
					SDL_SetRenderDrawColor(grender, 255, 0, 0, 255);
				}
				SDL_RenderFillRect(grender, &wall4);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);

				SDL_SetRenderDrawColor(grender, 139, 69, 19, 0);
				if (wallgone == false)
				{
					SDL_RenderFillRect(grender, &wall5);
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, friedchicken, 0, &chicken);
				SDL_RenderCopy(grender, twitch, 0, &twitchz);

				rectz rectzz[6];
				rectzz[0].plat = plat1; rectzz[1].plat = plat2; rectzz[2].plat = plat3; rectzz[3].plat = plat4; rectzz[4].plat = plat1roof; rectzz[5].plat = wall5;
				ballmove8();
				if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat1roof) || checkifontopof(heartman, wall5))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, plat1) || checkcollision(heartman, plat2) || checkcollision(heartman, plat3) || checkcollision(heartman, plat4) || checkcollision(heartman, plat1roof) || checkcollision(heartman, wall5))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, plat4) || checkifontopof(heartman, plat1roof) || checkifontopof(heartman, wall5))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, plat1) == 'l' && playerpos == 'a' || collisionside(heartman, plat2) == 'l' && playerpos == 'a' || collisionside(heartman, plat3) == 'l' && playerpos == 'a' || collisionside(heartman, plat4) == 'l' && playerpos == 'a' || collisionside(heartman, plat1roof) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat2) == 'r' && playerpos == 'd' || collisionside(heartman, plat3) == 'r' && playerpos == 'd' || collisionside(heartman, plat4) == 'r' && playerpos == 'd' || collisionside(heartman, plat1roof) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, plat1) || collisionsidebool(heartman, plat2) || collisionsidebool(heartman, plat3) || collisionsidebool(heartman, plat4) || collisionsidebool(heartman, plat1roof) || collisionsidebool(heartman, wall5))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				if (rectcollision(trihardd, twitchz) && hittryhard == false)
				{
					hittryhard = true;
				}
				if (rectcollision(twitchz, wall5))
				{
					Mix_PlayChannel(-1, doorbreak, 0);
					wall85x = -2105;
					wall85y = -10000;
					wallgone = true;
				}
				if (rectcollision(heartman, box) && twitch8x == -1000)
				{
					Mix_PlayChannel(-1, buttonpress, 0);
					twitchalive = true;
					twitch8x = 950;
					twitch8y = 20;
					box8y = 170;
				}
				if (playerx > 900 && playery < 170)
				{
					shoottrihards8 = false;
					for (int i = 0; i < 10; i++)
					{
						trihards8[i].rect = { 0,0,0,0 };
					}
				}
				if (playerx > 300 && spawntrihard8 == false)
				{
					spawntrihard8 = true;
					trihard8x = 0;
					trihard8y = 435;

				}
				if (spawntrihard8 == true)
				{
					SDL_RenderCopyEx(grender, TryHard, 0, &trihardd,trihardangle8,0,SDL_FLIP_NONE);
				}
				//initiate trihards
				if (onetime8 == true)
				{
					for (int i = 0; i < 10; i++)
					{
						int x = rand() % 2;
						trihards8[i].texture = TryHard;
						if (x == 0)
						{
							trihards8[i].rect = { 1200,25,35,35 };
						}
						if (x == 1)
						{
							trihards8[i].rect = { 1200,145,35,35 };
						}

					}
					onetime8 = false;
				}
				//DEATHS
				//reset smorc, trihard, player, trihardspawn,twitch,door,button
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, ballz1) || rectcollision(heartman, ballz2) || rectcollision(heartman, ballz3) || rectcollision(heartman, smorcz) || rectcollision(heartman, sjw) || rectcollision(heartman, sjw2) || rectcollision(heartman, trihardd))
				{
					if (rectcollision(heartman, sjw))
					{
						Mix_PlayChannel(-1, donttouchme, 0);
					}
					if (rectcollision(heartman, sjw2))
					{
						Mix_PlayChannel(-1, thisisrape, 0);
					}
					playerx = 0;
					playery = 500;
					spawntrihard8 = false;
					trihard8x = -100;
					trihard8y = -100;
					smorc8y = -100;
					smorcfall = false;
					hittryhard = false;
					wallgone = false;
					shoottrihards8 = true;
					box8y = 160;
					twitchalive = false;
					twitch8x = -1000;
					twitch8y = -1000;
					shoottrihards = true;
					onetime8 = true;
				}
				if (rectcollision(heartman, wall1) && wall1red == true || rectcollision(heartman, wall2) && wall2red == true || rectcollision(heartman, wall3) && wall3red == true || rectcollision(heartman, wall4) && wall4red == true)
				{
				
					playerx = 0;
					playery = 500;
					spawntrihard8 = false;
					trihard8x = -100;
					trihard8y = -100;
					smorc8y = -100;
					smorcfall = false;
					hittryhard = false;
					wallgone = false;
					shoottrihards8 = true;
					box8y = 160;
					twitchalive = false;
					twitch8x = -1000;
					twitch8y = -1000;
					shoottrihards = true;
					onetime8 = true;
				}
				for (int i = 0; i < 10; i++)
				{
					if (rectcollision(heartman, trihards8[i].rect))
					{
						playerx = 0;
						playery = 500;
						spawntrihard8 = false;
						trihard8x = -100;
						trihard8y = -100;
						smorc8y = -100;
						smorcfall = false;
						hittryhard = false;
						wallgone = false;
						shoottrihards8 = true;
						box8y = 160;
						twitchalive = false;
						twitch8x = -1000;
						twitch8y = -1000;
						shoottrihards = true;
						onetime8 = true;
					}
				}

			}
			else if (currentsurface == background9)
			{
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect lever = { lever9x,lever9y,50,chicken9h };
				SDL_Rect chickenbucketz = { chickenbucketz9x,chickenbucketz9y,75,75 };
				SDL_Rect chickenz = { chicken9x,chicken9y,45,45 };
				SDL_Rect stonewall = { 1100,0,100,stonewall9h };
				
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_SetRenderDrawColor(grender, 128, 128, 128, 255);
				SDL_RenderFillRect(grender, &lever);
				SDL_RenderFillRect(grender, &stonewall);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				SDL_RenderCopy(grender, friedchicken, 0, &chickenz);
				SDL_RenderCopy(grender, chickenbucket, 0, &chickenbucketz);
				if (checkifontopof(heartman, stonewall) || checkifontopof(heartman, lever))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, stonewall) || checkcollision(heartman, lever))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, stonewall) || checkifontopof(heartman, lever))
					{

						playerx += playervelx;
					}
					else
					{
						jumpframes = 0;
					}
				}
				if (rectcollision(chickenz, chickenbucketz) && levergo == false)
				{
					chicken9x = 900;
					chicken9y = 460;
					levergo = true;
				}
				else
				{
					if (levergo == true)
					{

					}
					else
					{
						chicken9x = playerx + 50;
						chicken9y = playery;
					}
					
				}
				if (levergo == true && lever9y != 594)
				{
					lever9y++;
					chickenbucketz9y++;
					chicken9y++;
					chicken9h--;
				}
				if (levergo == true && lever9y == 594)
				{
					stonewall9h--;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 500;
				}
			}
			else if (currentsurface == background10)
			{
				//SDL_Rect bullet = {bullet9x}
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect stone2 = { 0,0,100,50 };
				SDL_Rect stone = { 0,175,100,425 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect boshytxt = { boshy10x - 20, boshy10y - 20,300,25 };
	
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, stonewall, 0, &stone);
				SDL_RenderCopy(grender, stonewall, 0, &stone2);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[2];
				rectzz[0].plat = stone; rectzz[1].plat = stone2;
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				
				if (checkifontopof(heartman, stone) || checkifontopof(heartman, stone2))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, stone) || checkcollision(heartman, stone2) )
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, stone) || checkifontopof(heartman, stone2))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, stone) == 'l' && playerpos == 'a' || collisionside(heartman, stone2) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, stone) == 'r' && playerpos == 'd' || collisionside(heartman, stone2) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, stone) || collisionsidebool(heartman, stone2))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}

				
				if (rectcollision(heartman, Boshy) && grabboshi == false)
				{
					grabboshi = true;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
					SDL_RenderCopy(grender, boshytext, 0, &boshytxt);
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 50;
				}
			}
			else if (currentsurface == background11)
			{
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect tunnel = { 700,585,300,75 };
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				SDL_RenderCopy(grender, hole,0,&tunnel);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);


				if (playerx >= 750 && playerx <= 950)
				{
					playery++;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 500;
				}
			}
			else if (currentsurface == background12)
			{
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect leftdirt{ 0,0,750,650 };
				SDL_Rect rightdirt = { 950,0,300,650 };
				SDL_Rect tophole = { 750,0,200,100 };
				SDL_Rect rockback = { 750,100,200,550 };
				SDL_Rect spike1 = { 890,550,50,75 };
				SDL_Rect spike2 = { 760,350,50,75 };
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, dirt, 0, &leftdirt);
				SDL_RenderCopy(grender, dirt, 0, &rightdirt);
				SDL_RenderCopy(grender, hole2, 0, &tophole);
				SDL_RenderCopy(grender, rock, 0, &rockback);
				SDL_RenderCopyEx(grender, spike, 0, &spike1, 270, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike2, 90, 0, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				
				rectz rectzz[2];
				rectzz[0].plat = leftdirt; rectzz[1].plat = rightdirt;
				
				if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, leftdirt) || checkcollision(heartman, rightdirt))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 2, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, leftdirt) == 'l' && playerpos == 'a' || collisionside(heartman, rightdirt) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, leftdirt) == 'r' && playerpos == 'd' || collisionside(heartman, rightdirt) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, leftdirt) || collisionsidebool(heartman, rightdirt))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				
				
				
				if (playerx >= 700 && playerx <= 950)
				{
					noground = true;
					playery++;
				}
				else
				{
					noground = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, spike1) || rectcollision(heartman, spike2))
				{
					currentsurface = background11;
					playerx = 0;
					playery = 500;
					noground = false;
				}
			}
			else if (currentsurface == background13)
			{
				
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect dirtl1 = { 550,0,200,100 };
				SDL_Rect dirtl2 = { 350,0,200,350 };
				SDL_Rect dirtl3 = { 0,0,350,650 };
				SDL_Rect dirtr1 = { 950,0,300,650 };
				SDL_Rect dirtr2 = { 750,300,200,400 };
				SDL_Rect dirtr3 = {	550,575,200,100 };
				SDL_Rect rock1 = { 750,0,200,350 };
				SDL_Rect rock2 = { 550,100,200,475 };
				SDL_Rect rock3 = { 350,300,200,350 };
				SDL_Rect spike1 = { 750,300,200,50 };
				SDL_Rect spike2 = { 550, 525,200,50 };
				SDL_Rect spike3 = { 560,250,50,75 };
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, dirt, 0, &dirtl1);
				SDL_RenderCopy(grender, dirt, 0, &dirtl2);
				SDL_RenderCopy(grender, dirt, 0, &dirtl3);
				SDL_RenderCopy(grender, dirt, 0, &dirtr1);
				SDL_RenderCopy(grender, dirt, 0, &dirtr2);
				SDL_RenderCopy(grender, dirt, 0, &dirtr3);
				SDL_RenderCopy(grender, rock, 0, &rock1);
				SDL_RenderCopy(grender, rock, 0, &rock2);
				SDL_RenderCopy(grender, rock, 0, &rock3);
				SDL_RenderCopy(grender, spike, 0, &spike1);
				SDL_RenderCopy(grender, spike, 0, &spike2);
				SDL_RenderCopyEx(grender, spike, 0, &spike3, 90, 0, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[6];
				rectzz[0].plat = dirtl1; rectzz[1].plat = dirtl2; rectzz[0].plat = dirtl3; rectzz[1].plat = dirtr1; rectzz[0].plat = dirtr2; rectzz[1].plat = dirtr3;

				if (checkifontopof(heartman, dirtl1) || checkifontopof(heartman, dirtl2) || checkifontopof(heartman, dirtl3) || checkifontopof(heartman, dirtr1) || checkifontopof(heartman, dirtr2) || checkifontopof(heartman, dirtr3))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, dirtl1) || checkcollision(heartman, dirtl2) || checkcollision(heartman, dirtl3) || checkcollision(heartman, dirtr1) || checkcollision(heartman, dirtr2) || checkcollision(heartman, dirtr3))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, dirtl1) || checkifontopof(heartman, dirtl2) || checkifontopof(heartman, dirtl3) || checkifontopof(heartman, dirtr1) || checkifontopof(heartman, dirtr2) || checkifontopof(heartman, dirtr3))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, dirtl1) == 'l' && playerpos == 'a' || collisionside(heartman, dirtl2) == 'l' && playerpos == 'a' || collisionside(heartman, dirtl3) == 'l' && playerpos == 'a' || collisionside(heartman, dirtr1) == 'l' && playerpos == 'a' || collisionside(heartman, dirtr2) == 'l' && playerpos == 'a' || collisionside(heartman, dirtr3) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, dirtl1) == 'r' && playerpos == 'd' || collisionside(heartman, dirtl2) == 'r' && playerpos == 'd' || collisionside(heartman, dirtl3) == 'r' && playerpos == 'd' || collisionside(heartman, dirtr1) == 'r' && playerpos == 'd' || collisionside(heartman, dirtr2) == 'r' && playerpos == 'd' || collisionside(heartman, dirtr3) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, dirtl1) || collisionsidebool(heartman, dirtl2) || collisionsidebool(heartman, dirtl3) || collisionsidebool(heartman, dirtr1) || collisionsidebool(heartman, dirtr2) || collisionsidebool(heartman, dirtr3))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 6, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 6; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}



				if (playerx >= 350 && playerx <= 550)
				{
					noground = true;
					playery++;
				}
				else
				{
					noground = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, spike1) || rectcollision(heartman, spike2) || rectcollision(heartman, spike3))
				{
					currentsurface = background11;
					playerx = 0;
					playery = 500;
					noground = false;
				}

			}
			else if (currentsurface == background14)
			{
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect leftdirt = {0,0,350,650};
				SDL_Rect rightdirt = {550,0,600,650};
				SDL_Rect rockback = {350,0,200,650};
				SDL_Rect spike1 = {360,325,50,75};
				SDL_Rect spike2 = {490,175,50,75};
				SDL_Rect spike3 = { 360,600,50,75 };
				SDL_Rect spike4 = { 490,475,50,75 };
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, dirt, 0, &leftdirt);
				SDL_RenderCopy(grender, dirt, 0, &rightdirt);
				SDL_RenderCopy(grender, rock, 0, &rockback);
				SDL_RenderCopyEx(grender, spike, 0, &spike1, 90, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike2, 270, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike3, 90, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, spike, 0, &spike4, 270, 0, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);


				rectz rectzz[2];
				rectzz[0].plat = leftdirt; rectzz[1].plat = rightdirt;

				if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, leftdirt) || checkcollision(heartman, rightdirt))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 2, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, leftdirt) == 'l' && playerpos == 'a' || collisionside(heartman, rightdirt) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, leftdirt) == 'r' && playerpos == 'd' || collisionside(heartman, rightdirt) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, leftdirt) || collisionsidebool(heartman, rightdirt))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}

				if (playerx >= 350 && playerx <= 550)
				{
					noground = true;
					//playery++;
				}
				else
				{
					noground = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, spike1) || rectcollision(heartman, spike2) || rectcollision(heartman, spike3) || rectcollision(heartman, spike4))
				{
					currentsurface = background11;
					playerx = 0;
					playery = 500;
					noground = false;
				}
			}
			else if (currentsurface == background15)
			{
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect leftdirt{ 0,0,350,650 };
				SDL_Rect rightdirt = { 550,0,700,650 };
				SDL_Rect rockback = { 350,0,200,650 };
				SDL_Rect spike1 = { 375,250,50,75 };
				SDL_Rect spike2 = { 475,250,50,75 };
				SDL_Rect spike3 = { 475,500,50,75 };
				SDL_Rect spike4 = { 375,500,50,75 };
				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, dirt, 0, &leftdirt);
				SDL_RenderCopy(grender, dirt, 0, &rightdirt);
				SDL_RenderCopy(grender, rock, 0, &rockback);
				SDL_RenderCopyEx(grender, apple, 0, &spike1, 0, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, penguin, 0, &spike2, 0, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, windowsxp, 0, &spike3, 0, 0, SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, ubuntu, 0, &spike4, 0, 0, SDL_FLIP_NONE);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[2];
				rectzz[0].plat = leftdirt; rectzz[1].plat = rightdirt;

				if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, leftdirt) || checkcollision(heartman, rightdirt))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, leftdirt) || checkifontopof(heartman, rightdirt))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 2, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, leftdirt) == 'l' && playerpos == 'a' || collisionside(heartman, rightdirt) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, leftdirt) == 'r' && playerpos == 'd' || collisionside(heartman, rightdirt) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, leftdirt) || collisionsidebool(heartman, rightdirt))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 2, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 2; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}



				if (playerx >= 300 && playerx <= 950)
				{
					noground = true;
					//playery++;
				}
				else
				{
					noground = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, spike1) || rectcollision(heartman, spike3))
				{
					if (rectcollision(heartman, spike3))
					{
						
						Mix_PlayChannel(-1, windowsearrape, 0);
					}
					if (rectcollision(heartman, spike1))
					{
						Mix_PlayChannel(-1, macearrape, 0);
					}
					
					currentsurface = background11;
					playerx = 0;
					playery = 500;
					noground = false;
				}

			}
			else if (currentsurface == background16)
			{
				grabboshi = true;
	
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect LilPump = { lilpumpx,lilpumpy,lilpumpw,lilpumph };
				SDL_Rect Anele = { anelex,aneley,anelew,aneleh };
				SDL_Rect button1 = { 400,greenbuttony,50,greenbuttonh };
				SDL_Rect button2 = { 700,whitebuttony,50,whitebuttonh};
				SDL_Rect button3 = { 1000,brownbuttony,50,brownbuttonh };
				SDL_Rect wall = { 1100,0,100,wall16h };
				SDL_Rect wall2 = { 0,0,20,600 };
				SDL_Rect Uslogo = { uslogox,uslogoy,50,50 };
				SDL_Rect Uslogo2 = { uslogo2x,uslogo2y,50,50 };
				SDL_Rect rbutton1 = { 40,rbutton1y,10,15 };
				SDL_Rect rbutton2 = { 920,rbutton2y,10,15 };
				SDL_Rect rocket = { rocketx,rockety,50,50 };
				SDL_Rect Tigerwoods = { tigerx,tigery,200,tigerh };
				SDL_Rect Cfour = { cfourx,525,75,75 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, currentsurface, 0, 0);
				SDL_SetRenderDrawColor(grender, 47, 229, 59, 255);
				SDL_RenderFillRect(grender, &button1);
				SDL_SetRenderDrawColor(grender, 255, 255, 255, 255);
				SDL_RenderFillRect(grender, &button2);
				SDL_SetRenderDrawColor(grender, 159, 80, 11, 255);
				SDL_RenderFillRect(grender, &button3);
				SDL_RenderCopyEx(grender, tigerwoods, 0, &Tigerwoods, tigerangle, 0, SDL_FLIP_NONE);
				SDL_SetRenderDrawColor(grender, 98, 95, 92, 255);
				SDL_RenderFillRect(grender, &wall);
				SDL_RenderFillRect(grender, &wall2);
				SDL_SetRenderDrawColor(grender, 255, 0, 0, 255);
				SDL_RenderFillRect(grender, &rbutton1);
				SDL_RenderFillRect(grender, &rbutton2);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, cfour, 0, &Cfour);
				SDL_RenderCopy(grender, uslogo, 0, &Uslogo);
				SDL_RenderCopy(grender, uslogo, 0, &Uslogo2);
				SDL_RenderCopy(grender, missile, 0, &rocket);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				SDL_RenderCopyEx(grender, lilpumpcurrent, 0, &LilPump,lilpumpangle,0,SDL_FLIP_NONE);
				SDL_RenderCopyEx(grender, anele, 0, &Anele, aneleangle, 0, SDL_FLIP_NONE);

				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				ballmove16();
				rectz rectzz[5];
				rectzz[0].plat = button1; rectzz[1].plat = button2; rectzz[2].plat = button3; rectzz[3].plat = wall; rectzz[3].plat = wall2;

				if (checkifontopof(heartman, button1) || checkifontopof(heartman, button2) || checkifontopof(heartman, button3) || checkifontopof(heartman, wall) || checkifontopof(heartman, wall2))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, button1) || checkcollision(heartman, button2) || checkcollision(heartman, button3) || checkcollision(heartman, wall) || checkcollision(heartman, wall2))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, button1) || checkifontopof(heartman, button2) || checkifontopof(heartman, button3) || checkifontopof(heartman, wall) || checkifontopof(heartman, wall2))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 5, heartman);
						if (rectcollisionarray(rectzz, 5, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 5; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, button1) == 'l' && playerpos == 'a' || collisionside(heartman, button2) == 'l' && playerpos == 'a' || collisionside(heartman, button3) == 'l' && playerpos == 'a' || collisionside(heartman, wall) == 'l' && playerpos == 'a' || collisionside(heartman, wall2) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, button1) == 'r' && playerpos == 'd' || collisionside(heartman, button2) == 'r' && playerpos == 'd' || collisionside(heartman, button3) == 'r' && playerpos == 'd' || collisionside(heartman, wall) == 'r' && playerpos == 'd' || collisionside(heartman, wall2) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, button1) || collisionsidebool(heartman, button2) || collisionsidebool(heartman, button3) || collisionsidebool(heartman, wall) || collisionsidebool(heartman, wall2))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 5, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 5; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}

				if (checkifontopof(heartman, button1))
				{
					greenbutton = true;
				}
				if (checkifontopof(heartman, button2))
				{
					whitebutton = true;
				}
				if (checkifontopof(heartman, button3))
				{
					brownbutton = true;
				}
				if (greenbutton == true)//lil pump
				{
					greenbuttony = 595;
					greenbuttonh = 5;

				}
				if (whitebutton == true) //anele
				{
					whitebuttony = 595;
					whitebuttonh = 5;
				}
				if (brownbutton == true)//sjw
				{
					brownbuttony = 595;
					brownbuttonh = 5;
				}
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						if (rectcollision(bullets[i].rect, LilPump))
						{
							if (bullets[i].hit == 1)
							{

							}
							else
							{
								lilpumphealth--;
								bullets[i].hit = 1;
								bullets[i].out = 0;
							}
							
							
						}
						if (rectcollision(bullets[i].rect, Tigerwoods))
						{
							if (tigercounter > 700)
							{
								if (bullets[i].hit == 1)
								{

								}
								else
								{
									tigerwoodshealth--;
									bullets[i].hit = 1;
									bullets[i].out = 0;
								}
							}
						}
					}
				}
				if (rectcollision(rocket, Anele))
				{
					Mix_PlayChannel(-1, explosionsound, 0);
					anelealive = 0;
				}
				if (anelealive == 0)
				{
					if (anelew <= 0)
					{
						rocketx = -1000;
						rockety = -1001;
						uslogox = -1000;
						uslogoy = -1000;
						uslogo2y = -1000;
						uslogo2x = -1000;
					}
					else
					{
						SDL_RenderCopy(grender,explosion,0,&rocket);
						aneleangle++;
						aneleh--;
						anelew--;
					}
				}
				if (rectcollision(heartman, rbutton1))
				{
					if (press1 == 0)
					{
						press1 = 1;
					}
					else
					{
						if (press2 == 1)
						{
							press3 = 1;
						}
					}
				}
				if (rectcollision(heartman, rbutton2))
				{
					if (press1 == 1)
					{
						press2 = 1;
					}
				}
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				for (int i = 0; i < 21; i++)
				{
					if (rectcollision(heartman, bombz[i].rect))
					{
						for (int j = 0; j < 21; j++)
						{
							bombz[j].rect = { -100,-100,1,1 };
						}
						for (int x = 0; x < 50; x++)
						{
							chainz[x].rect = { -100,-100,1,1 };
						}
						lilpumpcurrent = lilpump1;
						tigerwoods = loadtexture("tiger woods.JPG");
						whitebutton = 0;
						brownbutton = 0;
						greenbutton = 0;
						greenbuttony = 570;
						whitebuttony = 570;
						brownbuttony = 570;
						greenbuttonh = 25;
						whitebuttonh = 25;
						brownbuttonh = 25;
						cfourx = 2000;
						lilpumpx = -100;
						lilpumpy = -100;
						lilpumph = 100;
						lilpumpw = 100;
						lilpumpangle = 0;
						lilpumpp1 = 0;
						lilpumpp2 = 0;
						lilpumpp3 = 0;
						lilpumpp4 = 0;
						lilpumpp5 = 0;
						lilpumpup = 1;
						currentchainz = 0;
						chainzcounter = 0;
						chainzspeed = 40;
						lilpumphealth = 40;
						playonce = 1;
						anelex = -600;
						aneley = -200;
						anelew = 100;
						aneleh = 100;
						aneleangle = 0;
						uslogox = -700;
						uslogoy = -700;
						uslogo2x = -700;
						uslogo2y = -700;
						aneleright = 1;
						bombzcounter = 0;
						currentbomz = 0;
						rbutton1y = -50;
						rbutton2y = -50;
						press1 = 0;
						press2 = 0;
						press3 = 0;
						rocketx = -1000;
						rockety = -1000;
						anelealive = 1;
						pausetimer = 0;
						anelemoveup = 0;
						haltlilpump = 0;
						haltallah = 0;
						tigercounter = 0;
						tigerx = 1100;
						tigery = 400;
						tigerangle = 0;
						tigerwoodshealth = 113;
						tigerh = 200;
						halttiger = 0;
						wall16h = 600;
						playerx = 100;
						playery = 0;
						Mix_HaltMusic();
					}
				}
				for (int i = 0; i < 50; i++)
				{
					if (rectcollision(heartman, chainz[i].rect))
					{
						Mix_PlayChannel(-1, motel6, 0);
						for (int j = 0; j < 21; j++)
						{
							bombz[j].rect = { -100,-100,1,1 };
						}
						for (int x = 0; x < 50; x++)
						{
							chainz[x].rect = { -100,-100,1,1 };
						}
						lilpumpcurrent = lilpump1;
						tigerwoods = loadtexture("tiger woods.JPG");
						whitebutton = 0;
						brownbutton = 0;
						greenbutton = 0;
						greenbuttony = 570;
						whitebuttony = 570;
						brownbuttony = 570;
						greenbuttonh = 25;
						whitebuttonh = 25;
						brownbuttonh = 25;
						cfourx = 2000;
						lilpumpx = -100;
						lilpumpy = -100;
						lilpumph = 100;
						lilpumpw = 100;
						lilpumpangle = 0;
						lilpumpp1 = 0;
						lilpumpp2 = 0;
						lilpumpp3 = 0;
						lilpumpp4 = 0;
						lilpumpp5 = 0;
						lilpumpup = 1;
						currentchainz = 0;
						chainzcounter = 0;
						chainzspeed = 40;
						lilpumphealth = 40;
						playonce = 1;
						anelex = -600;
						aneley = -200;
						anelew = 100;
						aneleh = 100;
						aneleangle = 0;
						uslogox = -700;
						uslogoy = -700;
						uslogo2x = -700;
						uslogo2y = -700;
						aneleright = 1;
						bombzcounter = 0;
						currentbomz = 0;
						rbutton1y = -50;
						rbutton2y = -50;
						press1 = 0;
						press2 = 0;
						press3 = 0;
						rocketx = -1000;
						rockety = -1000;
						anelealive = 1;
						pausetimer = 0;
						anelemoveup = 0;
						haltlilpump = 0;
						haltallah = 0;
						tigercounter = 0;
						tigerx = 1100;
						tigery = 400;
						tigerangle = 0;
						tigerwoodshealth = 113;
						tigerh = 200;
						halttiger = 0;
						wall16h = 600;
						playerx = 100;
						playery = 0;
						Mix_HaltMusic();
					}
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, LilPump) || rectcollision(heartman, Tigerwoods) || rectcollision(heartman, Anele) || rectcollision(heartman,Cfour))
				{
					if (rectcollision(heartman, LilPump))
					{
						Mix_PlayChannel(-1, motel6, 0);
					}
					for (int j = 0; j < 21; j++)
					{
						bombz[j].rect = { -100,-100,1,1 };
					}
					for (int x = 0; x < 50; x++)
					{
						chainz[x].rect = { -100,-100,1,1 };
					}
					lilpumpcurrent = lilpump1;
					tigerwoods = loadtexture("tiger woods.JPG");
					whitebutton = 0;
					brownbutton = 0;
					greenbutton = 0;
					greenbuttony = 570;
					whitebuttony = 570;
					brownbuttony = 570;
					greenbuttonh = 25;
					whitebuttonh = 25;
					brownbuttonh = 25;
					cfourx = 2000;
					lilpumpx = -100;
					lilpumpy = -100;
					lilpumph = 100;
					lilpumpw = 100;
					lilpumpangle = 0;
					lilpumpp1 = 0;
					lilpumpp2 = 0;
					lilpumpp3 = 0;
					lilpumpp4 = 0;
					lilpumpp5 = 0;
					lilpumpup = 1;
					currentchainz = 0;
					chainzcounter = 0;
					chainzspeed = 40;
					lilpumphealth = 40;
					playonce = 1;
					anelex = -600;
					aneley = -200;
					anelew = 100;
					aneleh = 100;
					aneleangle = 0;
					uslogox = -700;
					uslogoy = -700;
					uslogo2x = -700;
					uslogo2y = -700;
					aneleright = 1;
					bombzcounter = 0;
					currentbomz = 0;
					rbutton1y = -50;
					rbutton2y = -50;
					press1 = 0;
					press2 = 0;
					press3 = 0;
					rocketx = -1000;
					rockety = -1000;
					anelealive = 1;
					pausetimer = 0;
					anelemoveup = 0;
					haltlilpump = 0;
					haltallah = 0;
					tigercounter = 0;
					tigerx = 1100;
					tigery = 400;
					tigerangle = 0;
					tigerwoodshealth = 113;
					tigerh = 200;
					halttiger = 0;
					wall16h = 600;
					playerx = 100;
					playery = 0;
					Mix_HaltMusic();
				}

			}
			else if (currentsurface == background17)
			{

				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect floor1 = { 0,200,100,600 };
				SDL_Rect floor2 = { 100,250,100,600 };
				SDL_Rect floor3 = { 200,300,100,600 };
				SDL_Rect floor4 = { 300,350,100,600 };
				SDL_Rect floor5 = { 400,400,100,600 };
				SDL_Rect floor6 = { 500,450,100,600 };
				SDL_Rect floor7 = { 600,500,100,600 };
				SDL_Rect floor8 = { 700,550,100,600 };
				SDL_Rect floor9 = { 800,600,100,600 };
				SDL_Rect floor10 = { 900,600,300,600 };
				
				

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, cave, 0, 0);
				SDL_RenderCopy(grender, darkstone, 0, &floor1);
				SDL_RenderCopy(grender, darkstone, 0, &floor2);
				SDL_RenderCopy(grender, darkstone, 0, &floor3);
				SDL_RenderCopy(grender, darkstone, 0, &floor4);
				SDL_RenderCopy(grender, darkstone, 0, &floor5);
				SDL_RenderCopy(grender, darkstone, 0, &floor6);
				SDL_RenderCopy(grender, darkstone, 0, &floor7);
				SDL_RenderCopy(grender, darkstone, 0, &floor8);
				SDL_RenderCopy(grender, darkstone, 0, &floor9);
				SDL_RenderCopy(grender, darkstone, 0, &floor10);
				
				
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);


				rectz rectzz[10];
				rectzz[0].plat = floor1; rectzz[1].plat = floor2; rectzz[2].plat = floor3; rectzz[3].plat = floor4; rectzz[4].plat = floor5; rectzz[5].plat = floor6;  rectzz[6].plat = floor7;  rectzz[7].plat = floor8;  rectzz[8].plat = floor9;  rectzz[9].plat = floor10;
				

				if (checkifontopof(heartman, floor1) || checkifontopof(heartman, floor2) || checkifontopof(heartman, floor3) || checkifontopof(heartman, floor4) || checkifontopof(heartman, floor5) || checkifontopof(heartman, floor6) || checkifontopof(heartman, floor7) || checkifontopof(heartman, floor8) || checkifontopof(heartman, floor9) || checkifontopof(heartman, floor10))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, floor1) || checkcollision(heartman, floor2) || checkcollision(heartman, floor3) || checkcollision(heartman, floor4) || checkcollision(heartman, floor5) || checkcollision(heartman, floor6) || checkcollision(heartman, floor7) || checkcollision(heartman, floor8) || checkcollision(heartman, floor9) || checkcollision(heartman, floor10))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, floor1) || checkifontopof(heartman, floor2) || checkifontopof(heartman, floor3) || checkifontopof(heartman, floor4) || checkifontopof(heartman, floor5) || checkifontopof(heartman, floor6) || checkifontopof(heartman, floor7) || checkifontopof(heartman, floor8) || checkifontopof(heartman, floor9) || checkifontopof(heartman, floor10))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 10, heartman);
						if (rectcollisionarray(rectzz, 10, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 10; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, floor1) == 'l' && playerpos == 'a' || collisionside(heartman, floor2) == 'l' && playerpos == 'a' || collisionside(heartman, floor3) == 'l' && playerpos == 'a' || collisionside(heartman, floor4) == 'l' && playerpos == 'a' || collisionside(heartman, floor5) == 'l' && playerpos == 'a' || collisionside(heartman, floor6) == 'l' && playerpos == 'a' || collisionside(heartman, floor7) == 'l' && playerpos == 'a' || collisionside(heartman, floor8) == 'l' && playerpos == 'a' || collisionside(heartman, floor9) == 'l' && playerpos == 'a' || collisionside(heartman, floor10) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, floor1) == 'r' && playerpos == 'd' || collisionside(heartman, floor2) == 'r' && playerpos == 'd' || collisionside(heartman, floor3) == 'r' && playerpos == 'd' || collisionside(heartman, floor4) == 'r' && playerpos == 'd' || collisionside(heartman, floor5) == 'r' && playerpos == 'd' || collisionside(heartman, floor6) == 'r' && playerpos == 'd' || collisionside(heartman, floor7) == 'r' && playerpos == 'd' || collisionside(heartman, floor8) == 'r' && playerpos == 'd' || collisionside(heartman, floor9) == 'r' && playerpos == 'd' || collisionside(heartman, floor10) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, floor1) || collisionsidebool(heartman, floor2) || collisionsidebool(heartman, floor3) || collisionsidebool(heartman, floor4) || collisionsidebool(heartman, floor5) || collisionsidebool(heartman, floor6) || collisionsidebool(heartman, floor7) || collisionsidebool(heartman, floor8) || collisionsidebool(heartman, floor9) || collisionsidebool(heartman, floor10))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 10, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 10; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}


				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 0;
				}
			}
			else if (currentsurface == background18)
			{
				
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect floor1 = { 0,600,200,100 };
				SDL_Rect bridge = { 190,550,620,100 };
				SDL_Rect floor2 = { 800,600,600,100 };
				SDL_Rect castle = { 800,100,500,550 };
				SDL_Rect Stone = { Stonex,Stoney,400,1000 };
				SDL_Rect Rat = { ratx,Stoney - 50,100,50 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, cave, 0, 0);
				SDL_RenderCopy(grender, darkstone, 0, &floor1);
				SDL_RenderCopy(grender, darkstone, 0, &floor2);
				SDL_RenderCopy(grender, princesspalace, 0, &castle);
				SDL_RenderCopy(grender, hangingbridge, 0, &bridge);
				if (platformspawn == 1)
				{
				
					SDL_RenderCopy(grender, rock, 0, &Stone);
					SDL_RenderCopy(grender, rat, 0, &Rat);
				}
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);
				

				rectz rectzz[3];
				rectzz[0].plat = floor1; rectzz[1].plat = floor2;  rectzz[2].plat = Stone;

				if (checkifontopof(heartman, floor1) || checkifontopof(heartman, floor2) || checkifontopof(heartman, Stone))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, floor1) || checkcollision(heartman, floor2) || checkcollision(heartman, Stone))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, floor1) || checkifontopof(heartman, floor2) || checkifontopof(heartman, Stone))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 3, heartman);
						if (rectcollisionarray(rectzz, 3, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 3; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, floor1) == 'l' && playerpos == 'a' || collisionside(heartman, floor2) == 'l' && playerpos == 'a' || collisionside(heartman, Stone) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, floor1) == 'r' && playerpos == 'd' || collisionside(heartman, floor2) == 'r' && playerpos == 'd' || collisionside(heartman, Stone) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, floor1) || collisionsidebool(heartman, floor2) || collisionsidebool(heartman, Stone))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 3, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 3; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				if (playerx >= 190 && playerx <= 810 && platformspawn == 0)
				{
					noground = true;
					playery++;
				}
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 500;
				}
			}
			else if (currentsurface == background19)
			{
				if (background19once == 1)
				{
					Mix_PlayChannel(-1, mitchgetmeback, 0);
					background19once = 0;
				}
				
				noground = true;
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect platform = { platformx,platformy,400,1000 };
				SDL_Rect plat1 = {125,plat1y,75,10};
				SDL_Rect plat2 = {400,plat2y,75,10};
				SDL_Rect plat3 = {275,plat3y,75,10};
				SDL_Rect therat = { ratx,raty,100,50 };
				SDL_Rect mitchJones = { mitchjonesx,mitchjonesy,150,150 };
				SDL_Rect thebluelaser = { bluelaserx,bluelasery,bluelaserw,bluelaserh };
				SDL_Rect apebutton = { 140,380,40,10 };
				SDL_Rect sodabutton = { 140,380,40,10 };
				SDL_Rect Train = { apechickenx,apechickeny,150,200 };
				SDL_Rect Soda = { sodax, soday,100,100 };
				SDL_Rect Frost = { sodax, soday + 100,100,25 };
				SDL_Rect Shovel = { shovelx,shovely,25,100 };
				SDL_Rect fire1 = { 0,0,30,650 };
				SDL_Rect fire2 = { 570,0,1000,650 };
				SDL_Rect fire3 = { 0,0,1200,100 };
				SDL_Rect fire4 = { 0,600,1200,100 };
				SDL_Rect giantbottle = { giantbottlex, giantbottley, 500,250 };
				SDL_Rect Mira = { mirax, miray, 100,100 };
				SDL_Rect KGB = { kgbx,kgby,50,50 };
				SDL_Rect healthbar = { 1025,80,mitchhealthw,10 };
				SDL_Rect mitchBar = { 900,25,300,100 };
				SDL_Rect Patrick = { patrickx,patricky,300,500 };
				SDL_Rect button1z = { patrickx - 10,button119y,100,50 };
				SDL_Rect button2z = { patrickx - 10,button219y,100,50 };
				SDL_Rect button3z = { patrickx - 10,button319y,100,50 };
				SDL_Rect button4z = { patrickx - 10,button419y,100,50 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, lava, 0, 0);
				SDL_RenderCopy(grender,rock,0, &plat1);
				SDL_RenderCopy(grender, rock, 0, &plat2);
				SDL_RenderCopy(grender, rock, 0, &plat3);
				SDL_RenderCopy(grender, rock, 0, &platform);
				for (int i = 0; i < 10; i++)
				{
					SDL_RenderCopy(grender, rock, 0, &miraplatforms[i]);
				}
				if (apebuttonpress == 1)
				{
					SDL_SetRenderDrawColor(grender, 0, 255, 255, 0);
					SDL_RenderFillRect(grender, &apebutton);
				}
				if (sodabuttonpress == 1)
				{
					SDL_SetRenderDrawColor(grender, 0, 255, 255, 0);
					SDL_RenderFillRect(grender, &apebutton);
				}
				SDL_RenderCopy(grender, apechicken, 0, &Train);
				SDL_RenderCopy(grender, rat, 0, &therat);
				if (stagesix == 1)
				{
					SDL_RenderCopy(grender, fire, 0, &fire1);
					SDL_RenderCopy(grender, fire, 0, &fire2);
					SDL_RenderCopy(grender, fire, 0, &fire3);
					SDL_RenderCopy(grender, fire, 0, &fire4);
				}
				if (stagethree == 1 || stagefive == 1)
				{
					SDL_RenderCopyEx(grender, bluelaser, 0, &thebluelaser,315,0,SDL_FLIP_NONE);
				}
				else
				{
					SDL_RenderCopy(grender, bluelaser, 0, &thebluelaser);
				}
				SDL_RenderCopy(grender, shovel, 0, &Shovel);
				if (mitchjonesspawn == 1)
				{
					if (mitchexposed == 1)
					{
						SDL_SetRenderDrawColor(grender, 255, 0, 0, 0);
						SDL_RenderCopy(grender, mitchbar, 0, &mitchBar);
						SDL_RenderFillRect(grender, &healthbar);
						SDL_SetRenderDrawColor(grender, 255, 255, 255, 0);
					}
					else
					{
						SDL_SetRenderDrawColor(grender, 0, 0, 255, 0);
						SDL_RenderCopy(grender, mitchbar, 0, &mitchBar);
						SDL_RenderFillRect(grender, &healthbar);
						SDL_SetRenderDrawColor(grender, 255, 255, 255, 0);
					}
				}
				if (sodalife < 1)
				{
					SDL_RenderCopy(grender, sodanope, 0, &Soda);
					SDL_RenderCopy(grender, frostnova, 0, &Frost);
				}
				else if (sodarun == 1)
				{
					SDL_RenderCopy(grender, sodadead, 0, &Soda);
				}
				else
				{
					SDL_RenderCopy(grender, sodaw, 0, &Soda);
					SDL_RenderCopy(grender,frostnova,0,&Frost);
				}
				SDL_RenderCopy(grender, kgb, 0 ,&KGB);
				SDL_RenderCopy(grender, pissbottle, 0, &giantbottle);
				
				SDL_RenderFillRect(grender, &button1z);
				SDL_RenderFillRect(grender, &button2z);
				SDL_RenderFillRect(grender, &button3z);
				SDL_RenderFillRect(grender, &button4z);
				SDL_RenderCopy(grender, patrickdick, 0, &Patrick);
				SDL_RenderCopy(grender, miraw, 0, &Mira);
					if (mitchbye == 1)
					{
						SDL_RenderCopyEx(grender, mitchfunny, 0, &mitchJones, mitchangle, 0, SDL_FLIP_NONE);
					}
					else
					{
						SDL_RenderCopyEx(grender, mitchjones, 0, &mitchJones, mitchangle, 0, SDL_FLIP_NONE);
					}
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
					if (bullets[i].out == 0)
					{
						bullets[i].rect.x = -5000;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				ballmove19();

				rectz rectzz[14];
				rectzz[0].plat = plat1; rectzz[1].plat = plat2; rectzz[2].plat = platform; rectzz[3].plat = plat3;
				rectzz[5].plat = miraplatforms[0]; rectzz[6].plat = miraplatforms[1]; rectzz[7].plat = miraplatforms[2];
				rectzz[8].plat = miraplatforms[3]; rectzz[9].plat = miraplatforms[4]; rectzz[10].plat = miraplatforms[5];
				rectzz[11].plat = miraplatforms[6]; rectzz[12].plat = miraplatforms[7]; rectzz[13].plat = miraplatforms[8];
				rectzz[4].plat = miraplatforms[9];

				if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, platform) || checkifontopof(heartman, miraplatforms[0]) || checkifontopof(heartman, miraplatforms[1]) || checkifontopof(heartman, miraplatforms[2]) || checkifontopof(heartman, miraplatforms[3]) || checkifontopof(heartman, miraplatforms[4]) || checkifontopof(heartman, miraplatforms[5]) || checkifontopof(heartman, miraplatforms[6]) || checkifontopof(heartman, miraplatforms[7]) || checkifontopof(heartman, miraplatforms[8]) || checkifontopof(heartman, miraplatforms[9]))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, plat1) || checkcollision(heartman, plat2) || checkcollision(heartman, plat3) || checkcollision(heartman, platform) || checkcollision(heartman, miraplatforms[0]) || checkcollision(heartman, miraplatforms[1]) || checkcollision(heartman, miraplatforms[2]) || checkcollision(heartman, miraplatforms[3]) || checkcollision(heartman, miraplatforms[4]) || checkcollision(heartman, miraplatforms[5]) || checkcollision(heartman, miraplatforms[6]) || checkcollision(heartman, miraplatforms[7]) || checkcollision(heartman, miraplatforms[8]) || checkcollision(heartman, miraplatforms[9]))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, plat1) || checkifontopof(heartman, plat2) || checkifontopof(heartman, plat3) || checkifontopof(heartman, platform) || checkifontopof(heartman, miraplatforms[0]) || checkifontopof(heartman, miraplatforms[1]) || checkifontopof(heartman, miraplatforms[2]) || checkifontopof(heartman, miraplatforms[3]) || checkifontopof(heartman, miraplatforms[4]) || checkifontopof(heartman, miraplatforms[5]) || checkifontopof(heartman, miraplatforms[6]) || checkifontopof(heartman, miraplatforms[7]) || checkifontopof(heartman, miraplatforms[8]) || checkifontopof(heartman, miraplatforms[9]))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 14, heartman);
						if (rectcollisionarray(rectzz, 14, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 14; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, plat1) == 'l' && playerpos == 'a' || collisionside(heartman, plat2) == 'l' && playerpos == 'a' || collisionside(heartman, plat3) == 'l' && playerpos == 'a' || collisionside(heartman, platform) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[0]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[1]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[2]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[3]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[4]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[5]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[6]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[7]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[8]) == 'l' && playerpos == 'a' || collisionside(heartman, miraplatforms[9]) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, plat1) == 'r' && playerpos == 'd' || collisionside(heartman, plat2) == 'r' && playerpos == 'd' || collisionside(heartman, plat3) == 'r' && playerpos == 'd' || collisionside(heartman, platform) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[0]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[1]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[2]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[3]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[4]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[5]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[6]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[7]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[8]) == 'r' && playerpos == 'd' || collisionside(heartman, miraplatforms[9]) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, plat1) || collisionsidebool(heartman, plat2) || collisionsidebool(heartman, plat3) || collisionsidebool(heartman, platform) || collisionsidebool(heartman, miraplatforms[0]) || collisionsidebool(heartman, miraplatforms[1]) || collisionsidebool(heartman, miraplatforms[2]) || collisionsidebool(heartman, miraplatforms[3]) || collisionsidebool(heartman, miraplatforms[4]) || collisionsidebool(heartman, miraplatforms[5]) || collisionsidebool(heartman, miraplatforms[6]) || collisionsidebool(heartman, miraplatforms[7]) || collisionsidebool(heartman, miraplatforms[8]) || collisionsidebool(heartman, miraplatforms[9]))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 14, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 14; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				if (ratx >= 500 && mitchjonesspawn == 0)
				{
					if (raty > 700)
					{
						mitchjonesspawn = 1;
					}
					else
					{
						raty += 2;
						ratx += 2;
						
					}
				
				}
				if (ratcanttouch == 1)
				{

				}
				else
				{
					if (rectcollision(heartman, therat))
					{
						ratx += 2;
					}
				}
				if (rectcollision(mitchJones, Mira))
				{
					mitchspin = 1;
				}
				if (mitchspin == 1)
				{
					mitchangle += 5;
					if (mitchangle == 360)
					{
						mitchspin = 0;
						mitchmove = 1;
						miragone = 1;
						kgbx = -500;
						kgby = -500;
						mitchexposed = 1;
					}
				}
				if (rectcollision(heartman, apebutton) && apebuttonpress == 1 && mitchjoneslaser == 0)
				{
					apebuttonpress = 0;
					stagethree = 1;
					mitchjoneslaser = 0;
					bluelaserx = -200;
					bluelasery = -200;
					bluelaserw = 100;
					bluelaserh = 200;
					mitchjoneslaser = 0;
				}
				//shovel
				if (rectcollision(heartman, Shovel) && stagefive == 1)
				{
					shovelgrab = 1;
				}
				if (shovelgrab == 1)
				{
					shovelx = playerx + 50;
					shovely = playery - 50;
				}
				for (int i = 0; i < 15; i++)//if it hits shovel or soda dissapear
				{
					if (rectcollision(Shovel, dramashots[i].rect))
					{
						dramashots[i].out = 0;
					}
					if (rectcollision(Soda, dramashots[i].rect))
					{
						if (dramashots[i].out == 0)
						{

						}
						else
						{
							sodalife--;
						}
						dramashots[i].out = 0;
					}
				}
				
				if (rectcollision(heartman, sodabutton) && sodabuttonpress == 1)
				{
					Mix_PlayChannel(-1, usetheshovel, 0);
					sodabuttonpress = 0;
					stagefive = 1;
					mitchjonesy = 101;
					stagefour = 0;
					//reset all pissbottles
					for (int i = 0; i < 15; i++)
					{
						pissbottles[i].b = 0;
						pissbottles[i].angle = 0;
						pissbottles[i].hit = 0;
						pissbottles[i].out = 0;
						pissbottles[i].speed = 0;
						pissbottles[i].width = 0;
						pissbottles[i].rect = { -500,-500,50,50 };
						pissbottles[i].texture = pissbottle;
					}

					mitchjoneslaser = 0;
					bluelaserx = -200;
					bluelasery = -200;
					bluelaserw = 100;
					bluelaserh = 200;
					mitchjoneslaser = 0;
				}
				

				for (int i = 0; i < 5; i++)
				{
					
					if (rectcollision(bullets[i].rect, button1z) || rectcollision(bullets[i].rect, button2z) || rectcollision(bullets[i].rect, button3z) || rectcollision(bullets[i].rect, button4z))
					{
						if (patrickmove == 1)
						{
							bullets[i].hit = 1;
							bullets[i].out = 0;
							if (rectcollision(bullets[i].rect, button1z) == 1)
							{
								if (button1119y >= 3)
								{
									button119y = -1000;
								}
								else
								{
									button1119y++;
								}
								
							}
							if (rectcollision(bullets[i].rect, button2z) == 1)
							{
								if (button2219y >= 3)
								{
									button219y = -1000;
								}
								else
								{
									button2219y++;
								}
								
							}
							if (rectcollision(bullets[i].rect, button3z) == 1)
							{
								if (button3319y >= 3)
								{
									button319y = -1000;
								}
								else
								{
									button3319y++;
								}
								
							}
							if (rectcollision(bullets[i].rect, button4z) == 1)
							{
								if (button4419y >= 3)
								{
									button419y = -1000;
								}
								else
								{
									button4419y++;
								}
								
							}
						}
					
					}
				}
				if (button1119y >= 3)
				{
					button119y = -1000;
				}
				if (button2219y >= 3)
				{
					button219y = -1000;
				}
				if (button3319y >= 3)
				{
					button319y = -1000;
				}
				if (button4419y >= 3)
				{
					button419y = -1000;
				}

				if (button2219y >= 3 && button3319y >= 3 && button4419y >= 3)
				{
					if (patricky > 700)
					{
						
						stageeight = 0;
						for (int i = 0; i < 5; i++)
						{
							patricks[i].rect = { -1000,-1000,30,30 };
						}
						stagenine = 1;
					}
					
					patricky++;
					patrickmove = 0;
				}
				for (int i = 0; i < 5; i++)
				{
					if (miragone == 1)
					{
						if (rectcollision(bullets[i].rect, mitchJones))
						{
							if (bullets[i].hit == 1)
							{

							}
							else
							{
								bullets[i].hit = 1;
								bullets[i].out = 0;
								mitchhealth -= 10;
								if (mitchhealthw == 0)
								{

								}
								else
								{
									mitchhealthw -= 10;
								}
							}

						}
					}
				}
				if (mitchhealth <= 0)
				{
					mitchdead = 1;
				}
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}


				//death arcaneshots, arcanefall,pissbottles,bigbottle,minibigbottle,fireballs,laser,KGB,rocks,patricks,bigpatrick,brokenrecord,fallingtoofar
				for (int i = 0; i < 30; i++)
				{
					if (rectcollision(heartman, fallingblast[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						
						//cout << "fallingblast";
					}
				}
				for (int i = 0; i < 10; i++)
				{
					if (rectcollision(heartman, shootingblast[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "shootingblast";
					}
				}
				for (int i = 0; i < 15; i++)
				{
					if (rectcollision(heartman, pissbottles[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "pissbottles";
					}
				}
				//giant bottle
				for (int i = 0; i < 15; i++)
				{
					if (rectcollision(heartman, pyroblasts[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "pyroblasts";
					}
				}
				for (int i = 0; i < 5; i++)
				{
					if (rectcollision(heartman, fallingrocks[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "fallingrocks";
					}
				}
				for (int i = 0; i < 10; i++)
				{
					if (rectcollision(heartman, brokenrecords[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "brokenrecords";
					}
				}
				for (int i = 0; i < 5; i++)
				{
					if (rectcollision(heartman, patricks[i].rect))
					{
						if (!BossInvincible)
						{
							death++;
							BossInvincible = true;
						}
						//cout << "patricks";
					}
				}
				if (rectcollision(heartman, thebluelaser) || rectcollision(heartman, KGB) || rectcollision(heartman, Patrick))
				{
					if (!BossInvincible)
					{
						death++;
						BossInvincible = true;
					}
					//cout << "KGB,bluelaser,Patrick";
				}
				/*if (rectcollision(heartman, fire1) || rectcollision(heartman, fire2) || rectcollision(heartman, fire3) || rectcollision(heartman, fire4))
				{
					if (stagesix == 1)
					{
						death++;
					}
					
				}*/
				SDL_Rect bigbottle = { 275,162,100,100 };
				if (stagefour == 1 && rectcollision(heartman, bigbottle))
				{
					if (!BossInvincible)
					{
						death++;
						BossInvincible = true;
					}
					//cout << "bottlebig";
				}
				if (stagefour == 1 && rectcollision(heartman, giantbottle))
				{
					if (!BossInvincible)
					{
						death++;
						BossInvincible = true;
					}
					//cout << "bottlegiant";
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					if (!BossInvincible)
					{
						death++;
						BossInvincible = true;
					}
				}
				if (playery >= 700)
				{
					if (!BossInvincible)
					{
						death++;
						BossInvincible = true;
					}
				}
				if (BossInvincible)
				{
					bossinvinciblecounter++;
					if (bossinvinciblecounter >= 60)
					{
						bossinvinciblecounter = 0;
						BossInvincible = false;
					}
				}
				if (death == 3)
				{
					Mix_HaltMusic();
					Mix_HaltChannel(-1);
					currentsurface = background18;
					playerx = 0;
					playery = 450;
					death = 0;
					ratx = 400;
					raty = 535;
					mitchjonesx = -100;
					mitchjonesy = -100;
					mitchangle = 0;
					mitchjonesspawn = 0;
					mitchjoneslaser = 0;
					bluelaserx = -200;
					bluelasery = -200;
				 bluelaserw = 100;
				 mitchfirsthalt = 1;
					bluelaserh = 200;
					mitchmoveup = 1;
					mitchmovedown = 0;
					//to test stage four put stage four to 1 stage one to 0
					 stageone = 1;
					stagetwo = 0;
					stagethree = 0;
					stagefour = 0;
					stagefive = 0;
					 stagesix = 0;
					stageseven = 0;
					 stageeight = 0;
					stagenine = 0;
					stageten = 0;
					stagetwofirsttime = 1;
					 currentblast = 0;
					blastcounter = 0;
					randomcounter = 100;
					for (int i = 0; i < 30; i++)
					{
						fallingblast[i].hit = 0;
						fallingblast[i].out = 0;
						fallingblast[i].b = 0;
						fallingblast[i].rect = { -1000,-1000,50,50 };
						fallingblast[i].texture = arcaneblast;
					}
					for (int i = 0; i < 10; i++)
					{
						shootingblast[i].hit = 0;
						shootingblast[i].out = 0;
						shootingblast[i].b = 0;
						shootingblast[i].rect = { -1200,-1200,50,50 };
						shootingblast[i].texture = arcaneblast;
					}
					currentshootingblast = 0;
					shootingblastcounter = 0;
					shootlasercounter = 1;
					lasercharge = 0;
					 apebuttonpress = 0;
					 apechickenx = -300;
					 apechickeny = -300;
					 apesoundnumber = 0;
					apebuttononce = 1;
					stagethreeonce = 1;
					for (int i = 0; i < 15; i++)
					{
						pissbottles[i].b = 0;
						pissbottles[i].angle = 0;
						pissbottles[i].hit = 0;
						pissbottles[i].out = 0;
						pissbottles[i].speed = 0;
						pissbottles[i].width = 0;
						pissbottles[i].rect = { -500,-500,50,50 };
						pissbottles[i].texture = pissbottle;
					}
					 pissbottlecounter = 1;
					 currentpissbottle = 0;
					 stagefouronce = 1;
					sodabuttonpress = 0;
					 sodax = -300;
					 soday = -300;
					 shovelx = -300;
					 shovely = -300;
					 sodabuttontimer = 0;
					 stagefiveonce = 1;
					 for (int i = 0; i < 15; i++)
					 {
						 dramashots[i].b = 0;
						 dramashots[i].hit = 0;
						 dramashots[i].out = 0;
						 dramashots[i].rect = { -500,-500,100,20 };
						 dramashots[i].texture = 0;
					 }
					dramashotcounter = 1;
					 currentdrama = 0;
					 sodacirclex = 0;
					 sodacircley = 0;
					 sodacircleradius = 500;
					 shovelgrab = 0;
					sodalife = 5;
					giantbottlex = -1000;
					 giantbottley = -1000;
					bottleonce = 1;
					randomlaser = rand() % 200 + 450;
					 sodarun = 0;
					sodacurrentsong = 1;
					sodaruncounter = 0;
					 stagesixonce = 1;
					 mitchcircleangle = 0;
					 for (int i = 0; i < 15; i++)
					 {
						 pyroblasts[i].texture = pyroblast;
						 pyroblasts[i].rect = { -500,-500,30,30 };
						 pyroblasts[i].out = 0;
						 pyroblasts[i].b = 0;
					 }
					 pyroblastcounter = 1;
					 currentpyroblast = 0;
					 stagesixendcounter = 1;
					 mirax = -500;
					 miray = -500;
					 stagesevenonce = 1;
					 plat1y = 390;
					 plat2y = 390;
					 plat3y = 262;
					 platformy = 585;
					 miraplatformcounter = 1;
					 currentmiraplatform = 0;
					 miraplatformx1count = 0;
					 miraplatformx2count = 0;
					 miraplatformx3count = 0;
					 miraplatformx4count = 0;
					 kgbx = -1000;
					 kgby = -1000;
					 kgbgoleft = 0;
					 kgbgoright = 1;
					 kgbperiod = .002;
					 kgbamplitude = 300;
					 for (int i = 0; i < 5; i++)
					 {
						 fallingrocks[i].texture = arock;
						 fallingrocks[i].rect = { -600,-600,40,40 };
					 }
					 for (int i = 0; i < 5; i++)
					 {
						 fallingrockhelp[i].texture = warning;
						 fallingrockhelp[i].rect = { -600,-600,40,40 };
						 fallingrockhelp[i].out = 0;
					 }
					 for (int i = 0; i < 10; i++)
					 {
						 miraplatforms[i] = { -500,-500,75,10 };
					 }
					 currentrock = 0;
					 kgbspeed = 2;
					 miramove = 0;
					 mitchspin = 0;
					 mitchmove = 1;
					 miragone = 0;
					 for (int i = 0; i < 10; i++)
					 {
						 brokenrecords[i].texture = brokenrecord;
						 brokenrecords[i].rect = { -200,-200,30,30 };
					 }
					 currentbrokenrecord = 0;
					 mitchhealthw = 150;
					 mitchexposed = 0;
					 mitchhealth = 150;
					 mitchdead = 0;
					 for (int i = 0; i < 5; i++)
					 {
						 patricks[i].texture = patrickdick;
						 patricks[i].rect = { -500,-500,75,75 };
						 patricks[i].out = 0;
					 }
					 stageeightonce = 1;
					 currentpatrick = 0;
					 patrickcounter = 1;
					patrickx = -1000;
					 patricky = -1000;
					 patrickmove = 0;
					 button119y = -1000;
					 button219y = 300;
					 button319y = 400;
					 button419y = 500;
					 button1119y = 0;
					 button2219y = 0;
					 button3319y = 0;
					 button4419y = 0;

					 background19once = 1;
					mirafight1 = 1;
					 mirafight2 = 1;
					 mitchfight11 = 0;
					stagenineonce = 1;
					 monologuecounter = 1;
					 mitchbye = 0;
					 stagetenonce = 1;
					 notonwow = 1;
					 brokenrecordsound = 1;
					 ratcanttouch = 0;
					 platformx = 100;
					 platformspawn = 0;
					 Stonex = -1000;
					 Stoney = -1000;
					 death = 0;

				}



			}
			else if (currentsurface == background20)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect roblox1 = { 600,roblox1y,200,300 };
				SDL_Rect roblox2 = { 1000,roblox2y,200,300 };
				SDL_Rect text = { 650,200,500,50 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background20, 0, 0);
				SDL_RenderCopy(grender, robloxman, 0, &roblox1);
				SDL_RenderCopy(grender, robloxman2, 0, &roblox2);
				SDL_RenderCopy(grender,youshallnotpass, 0, &text);
				

				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);






				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						if (rectcollision(bullets[i].rect, roblox1))
						{
							Mix_PlayChannel(-1, oof, 0);
							robloxhealth1--;
							bullets[i].out = 0;
							bullets[i].hit = 1;

						}
						if (rectcollision(bullets[i].rect, roblox2))
						{
							Mix_PlayChannel(-1, oof, 0);
							robloxhealth2--;
							bullets[i].out = 0;
							bullets[i].hit = 1;

						}
					}
					
				}
				if (robloxhealth1 <= 0)
				{
					if (roblox1dead == 0)
					{
						Mix_HaltChannel(-1);
						Mix_PlayChannel(-1, oofear, 0);
						roblox1dead = 1;
					}
					roblox1y++;
				}
				if (robloxhealth2 <= 0)
				{
					if (roblox2dead == 0)
					{
						Mix_HaltChannel(-1);
						Mix_PlayChannel(-1, oofear, 0);
						roblox2dead = 1;
					}
					roblox2y++;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, roblox1) || rectcollision(heartman, roblox2))
				{
					currentsurface = background18;
					playerx = 0;
					playery = 500;
					robloxhealth1 = 10;
					robloxhealth2 = 20;
					roblox1dead = 0;
					roblox2dead = 0;
					roblox2y = 350;
					roblox1y = 350;
				}

			}
			else if (currentsurface == background21)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };



				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background21, 0, 0);


				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);




				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
				if (currentkeystatereset[SDL_SCANCODE_Q] == 1)
				{
					playerx = 0;
					playery = 500;
				}
			}
			else if (currentsurface == background22)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect Barney = { barneyx,barneyy,barneyw,barneyh };
				SDL_Rect Demon = { demonx,demony,100,100 };
				SDL_Rect Laser = { barneyx - laserx,barneyy + 10 - 20,laserw,20 };
				SDL_Rect deathBall = { barneyx-50,barneyy + 75,200,200 };
				SDL_Rect lilPump = { 900,lilpump22y,100,100 };
				SDL_Rect barneyhead = { barneyheadx,barneyheady,100,100 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background22, 0, 0);
				SDL_RenderCopy(grender, demon, 0, &Demon);
				if (barneyheadspawn == 0)
				{
					if (barneymove == 0 && barneysound3 == 1)
					{
						SDL_RenderCopy(grender, barney, 0, &Barney);
					}
					else if (barneysound3 == 0)
					{
						SDL_RenderCopy(grender, evilbarney2, 0, &Barney);
					}
					else
					{
						SDL_RenderCopy(grender, evilbarney, 0, &Barney);
					}
				}
				if (barneyheadspawn == 1)
				{
					SDL_RenderCopy(grender, evilbarneyhead, 0, &barneyhead);
				}
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				if (barneybiglaser == 1 && barneyheadspawn == 0)
				{
					if (lilpumpfall == 0)
					{
						Mix_PlayChannel(-1, chargelaser, 0);
						SDL_RenderCopy(grender, deathball, 0, &deathBall);
					}
					if (lilpumpfallcounter == 500)
					{
						Mix_HaltChannel(-1);
						lilpumpfall = 1;
					}
					lilpumpfallcounter++;
				}
				if (lilpumpfall == 1)
				{
					if (lilpumplaughonce == 1)
					{
						Mix_PlayChannel(-1, lilpumplaugh, 0);
						lilpumplaughonce = 0;
					}
					SDL_RenderCopy(grender, lilpump2, 0, &lilPump);
					lilpump22y += 4;
				}
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				ballmove22();

				if (barneysound1 == 1)
				{
					Mix_PlayChannel(-1, barneyheyeveryone, 0);
					barneysound1 = 0;
				}
				if (barneysound2 == 1 && barneymove == 0)
				{
					
						Mix_PlayChannel(-1, barneyletsplaydie, 0);
						barneysound2 = 0;
						
					
				}
				if (barneysound2 == 0 && barneysound3 == 1)
				{
					if (Mix_Playing(-1) == 0)
					{
						
						Mix_PlayChannel(-1, barneydemon2, 0);
						barneysound3 = 0;
					}
				}
				if (barneysound3 == 0 && barneysound4 == 1)
				{
					if (Mix_Playing(-1) == 0)
					{
						demonx = 900;
						demony = 100;
						Mix_PlayChannel(-1, barneydemon, 0);
						barneysound4 = 0;
					}
				}
				if (barneysound4 == 0 && barneysound5 == 1)
				{
					if (Mix_Playing(-1) == 0)
					{
						Mix_PlayChannel(-1, barneyherewego, 0);
						barneysound5 = 0;
					}
				}
				if (barneysound5 == 0)
				{
					if (Mix_PlayingMusic() == 0 && lilpumpfall == 0)
					{
						Mix_PlayMusic(barneysong,0);
					}
				}
				if (barneysound3 == 0)
				{
					if (barneyy <= 200)
					{

					}
					else
					{
						barneyy--;
						barneyh++;
					}
					
				}
				if (barneysound1 == 0 && barneymove == 1 )
				{
				
					if (barneyy >= 430)
					{

					}
					else
					{
						barneyy += 3;
					}
					if (barneyx == 900)
					{

					}
					else
					{
						barneyx += 1;
					}
					if (barneyx == 900 && barneyy >= 400)
					{
						barneymove = 0;
					}
					

				}
				if (rectcollision(heartman, barneyhead))
				{
					barneyheadx += 5;
					if (barneyheadx >= 1200)
					{
						barneyhead2x = 50;
					}
				}
				if (rectcollision(lilPump, Demon))
				{
					demonx = -1000;
					demony = -1000;
				}
				if (rectcollision(lilPump, Barney))
				{
					if (barneyy >= 500)
					{
						barneyheadspawn = 1;
						Mix_HaltMusic();
						barneyy += 4;
							Mix_PlayChannel(-1, scream, 0);
	
						
					}
					else
					{
						barneyy += 4;
						barneyh--;
					}
				}

				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}

				for (int i = 0; i < 5; i++)
				{
					if (currentkeystatereset[SDL_SCANCODE_Q] == 1 || rectcollision(heartman, barneylaser[i].rect) || rectcollision(heartman, demonlaser[i].rect) || rectcollision(heartman, Barney))
					{
						Mix_HaltChannel(-1);
						Mix_HaltMusic();
						currentsurface = background21;
						playerx = 0;
						 barneyx = 500;
						 barneyy = 250;
						 barneyw = 200;
						 barneyh = 200;
						 demonx = -900;
						 demony = -1000;
						 barneysound1 = 1;
						 barneysound2 = 1;
					 barneysound3 = 1;
						 barneysound4 = 1;
					 barneysound5 = 1;
						 barneysound6 = 1;
						 barneymove = 1;
						 for (int i = 0; i < 5; i++)
						 {
							 barneylaser[i].texture = ladder;
							 barneylaser[i].rect = { -500,-500,75,20 };
							 demonlaser[i].texture = ladder;
							 demonlaser[i].rect = { -500,-500,75,20 };
						 }
						 barneyonce = 0;
						 currentbarneylaser = 0;
						 currentdemonlaser = 0;
						lasercounter = 1;
						 barneybiglaser = 0;
						 laserw = 1000;
						 laserx = 1000;
						 laserangle = 150;
						 lilpumpfall = 0;
						 lilpump22y = -105;
						 lilpumpfallcounter = 0;
						 lilpumplaughonce = 1;
						 barneyheadspawn = 0;
						 barneyheadx = 900;
						 barneyheady = 500;
						 barneyhead2x = -100;
						 barneyset = 0;
						 dontshowbutton = 0;
						 platFormy = 600;

					}
				}
			}
			else if (currentsurface == background23)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect barneyHead = { barneyhead2x,barneyheady,100,100 };
				SDL_Rect button = { 550,580,50,25 };
				SDL_Rect platform = { 500,platFormy,500,1000 };


				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background23, 0, 0);
				SDL_RenderFillRect(grender, &platform);
				if (dontshowbutton == 0)
				{
					SDL_RenderFillRect(grender, &button);
				}
				
				SDL_RenderCopy(grender, evilbarneyhead, 0, &barneyHead);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[1];
				rectzz[0].plat = platform;

				if (checkifontopof(heartman, platform))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, platform))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, platform))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 1, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, platform) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, platform) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, platform))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}

				if (dontshowbutton == 1)
				{
					if (Mix_PlayingMusic() == 0)
					{
						Mix_PlayMusic(perfectboy, 0);
						perfectboyplay = 0;
					}
					
					if (playerx <= 500)
					{
						playerx -= playervelx;
					}
					if (playerx >= 950)
					{
						playerx -= playervelx;
					}
					platFormy--;
					playery--;
					
				}
				if (rectcollision(heartman, button) && barneyset == 1)
				{
					dontshowbutton = 1;
				}
				if (rectcollision(heartman, barneyHead))
				{
					if (barneyhead2x >= 300)
					{
						barneyset = 1;
					}
					else
					{
						barneyhead2x += 5;
					}
					
				}
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
			}
			else if (currentsurface == background24)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect platform = { 500,platFormy,500,1000 };
				SDL_Rect credits = { 50,300,700,75 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background24, 0, 0);
				SDL_RenderFillRect(grender, &platform);
				SDL_RenderCopy(grender, credits1, 0, &credits);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[1];
				rectzz[0].plat = platform;

				if (checkifontopof(heartman, platform))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}
			
				if (checkcollision(heartman, platform))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, platform))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 1, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, platform) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, platform) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, platform))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}
				if (dontshowbutton == 1)
				{
					if (playerx <= 500)
					{
						playerx -= playervelx;
					}
					if (playerx >= 950)
					{
						playerx -= playervelx;
					}
					platFormy--;
					playery--;

				}

				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
			}
			else if (currentsurface == background25)
			{
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect platform = { 500,platFormy,500,1000 };
				SDL_Rect credits = { 50,200,800,75 };

				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background25, 0, 0);
				SDL_RenderFillRect(grender, &platform);
				SDL_RenderCopy(grender, credits2, 0, &credits);
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);

				rectz rectzz[1];
				rectzz[0].plat = platform;

				if (checkifontopof(heartman, platform))
				{
					playery -= gravityspeed;
					jumpagain = true;
					secondjump = false;
					//cout << "topof";
				}

				if (checkcollision(heartman, platform))
				{
					playerx -= playervelx;

					if (checkifontopof(heartman, platform))
					{

						playerx += playervelx;
						checkifontopofarray(rectzz, 1, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							playerx -= playervelx;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else //this is for side glitch
					{
						if (collisionside(heartman, platform) == 'l' && playerpos == 'a')
						{
							//cout << "a";
							playerx += playervelx;
						}
						if (collisionside(heartman, platform) == 'r' && playerpos == 'd')
						{
							//cout << "d";
							playerx += playervelx;
						}
					}
					if (collisionsidebool(heartman, platform))
					{
						//checkifonsideofarray(rectzz, 6, heartman);
						if (rectcollisionarray(rectzz, 1, heartman))
						{
							jumpframes = 0;
							//reset all bool values
							for (int i = 0; i < 1; i++)
							{
								rectzz[i].hit = false;
							}
						}
					}
					else
					{
						jumpframes = 0;
					}
				}

				if (dontshowbutton == 1)
				{
					if (playerx <= 500)
					{
						playerx -= playervelx;
					}
					if (playerx >= 950)
					{
						playerx -= playervelx;
					}
					platFormy--;
					playery--;

				}
				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
			}
			else if (currentsurface == background26)
			{
				if (cheeronce == 1)
				{
					Mix_PlayChannel(-1, cheers, 0);
					cheeronce = 0;
				}
				if (Mix_PlayingMusic() == 0 && perfectboyplay == 1)
				{
					Mix_PlayMusic(perfectboy, 0);
					perfectboyplay = 0;
				}
				if (Mix_PlayingMusic() == 0 && perfectboyplay == 0)
				{
					Mix_PlayMusic(fleshandbones, 0);
					perfectboyplay = 1;
				}
				grabboshi = true;
				SDL_Rect heartman = { playerx,playery,75,75 };
				SDL_Rect Boshy = { boshy10x,boshy10y,25,25 };
				SDL_Rect platform = { 500,platFormy,500,1000 };
				SDL_Rect credits = { 350,50,500,50 };
				SDL_Rect brandonflowers = { 100,500,60,60 };
				SDL_Rect Stage = { 0,400,400,200 };
				SDL_Rect robertsmith = { 250,500,60,60 };
				SDL_Rect scott = { 1100,500,75,75 };
				SDL_Rect scottmessage = { 800,200,400,30 };
				SDL_Rect robertmessage = { 200,200,600,30 };
				SDL_Rect brandonmessage = { 100,200,600,30 };



				SDL_RenderClear(grender);
				SDL_SetRenderDrawColor(grender, 0, 0, 0, 255);
				SDL_RenderCopy(grender, background26, 0, 0);
				SDL_RenderFillRect(grender, &platform);
				SDL_RenderCopy(grender, credits3, 0, &credits);
				SDL_RenderCopy(grender, stage, 0, &Stage);
				SDL_RenderCopy(grender, robert, 0, &robertsmith);
				SDL_RenderCopy(grender, brandon, 0, &brandonflowers);
				SDL_RenderCopy(grender, scottfitzgerald, 0, &scott);
				if (rectcollision(heartman, scott))
				{
					SDL_RenderCopy(grender, scotttext, 0, &scottmessage);
				}
				if (rectcollision(heartman, brandonflowers))
				{
					SDL_RenderCopy(grender, brandontalk, 0, &brandonmessage);
				}
				if (rectcollision(heartman, robertsmith))
				{
					SDL_RenderCopy(grender, roberttalk, 0, &robertmessage);
				}
				
				SDL_RenderCopy(grender, boshy, 0, &Boshy);
				for (int i = 0; i < 5; i++)
				{
					if (bullets[i].out == 1)
					{
						SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
						bullets[i].rect.x += 15;
					}
				}
				SDL_RenderCopy(grender, currentheart, 0, &heartman);


				if (playerx < 0)
				{
					playerx -= playervelx;
				}
				if (playerx + 100 > 1200)
				{
					playerx -= playervelx;
				}

				if (bulletspawn == true)
				{
					for (int i = 0; i < 5; i++)
					{
						bullets[i].texture = dot;
						bullets[i].rect = { 0,0,10,10 };
						bullets[i].out = 0;
					}
					bulletspawn = false;
				}
				if (grabboshi == true)
				{
					if (boshishoot == true)
					{

					}
					boshy10x = playerx + 50;
					boshy10y = playery + 10;
				}
			}
			else
			{
				SDL_RenderCopy(grender, currentsurface, 0, 0);

			}
			//in and out of levels
			if (playerx > 1200)
			{
				if (currentsurface == background)
				{
					currentsurface = background2;
					playerx = 0;
				}
				else if (currentsurface == background2)
				{
					currentsurface = background3;
					playerx = 0;
				}
				else if (currentsurface == background3)
				{
					currentsurface = background4;
					playerx = 0;
				}
				else if (currentsurface == background4)
				{
					currentsurface = background5;
					playerx = 0;
				}
				else if (currentsurface == background5)
				{
					currentsurface = background6;
					playerx = 0;
				}
				else if (currentsurface == background6)
				{
					currentsurface = background7;
					playerx = 0;
					playery = 50;
				}
				else if (currentsurface == background7)
				{
					currentsurface = background8;
					playerx = 0;
					//playery = 50;
				}
				else if (currentsurface == background8)
				{
					currentsurface = background9;
					playerx = 0;
					playery = 50;
				}
				else if (currentsurface == background9)
				{
					currentsurface = background10;
					playerx = 0;
					playery = 50;
				}
				else if (currentsurface == background10)
				{
					currentsurface = background11;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					//playery = 50;
				}
				else if (currentsurface == background16)
				{
					currentsurface = background17;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					playery = 50;
				}
				else if (currentsurface == background17)
				{
					currentsurface = background18;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					//playery = 50;
				}
				else if (currentsurface == background20)
				{
					currentsurface = background21;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					//playery = 50;
				}
				else if (currentsurface == background21)
				{
					currentsurface = background22;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					//playery = 50;
				}
				else if (currentsurface == background22)
				{
					currentsurface = background23;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					//playery = 50;
				}
			}
			if (playerx > 900)
			{
				if (currentsurface == background18)
				{
					noground = false;
					currentsurface = background20;
					playerx = 0;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
					playery = 500;
				}
			}
			if (playery + 50 <= 0)
			{
				if (jumpagain == true)
				{
					if (currentsurface == background19)
					{
						if (stageten == 1)
						{
							Mix_HaltMusic();
							currentsurface = background18;
							playery = 500;
							platformspawn = 1;
							Stonex = 400;
							Stoney = 600;
						}

					}
					if (currentsurface == background23)
					{
						currentsurface = background24;
						playery = 500;
						platformspawn = 1;
						platFormy = 600;


					}
					else if (currentsurface == background24)
					{
						currentsurface = background25;
						playery = 500;
						platformspawn = 1;
						platFormy = 600;

					}
					else if (currentsurface == background25)
					{
						currentsurface = background26;
						playery = 500;
						platformspawn = 1;
						platFormy = 600;
					}
				}
			}
			if (playery >= 650)
			{
				if (currentsurface == background11)
				{
					currentsurface = background12;
					playery = 0;
				}
				else if (currentsurface == background12)
				{
					currentsurface = background13;
					playery = 0;
				}
				else if (currentsurface == background13)
				{
					currentsurface = background14;
					playery = 0;
				}
				else if (currentsurface == background14)
				{
					currentsurface = background15;
					playery = 0;
				}
				else if (currentsurface == background15)
				{
					noground = false;
					currentsurface = background16;
					playery = 0;
				}
				else if (currentsurface == background18)
				{
					noground = true;
					currentsurface = background19;
					playery = 0;
				}
			}
			
			if (playerx < 0)
			{
				if (currentsurface == background2)
				{
					currentsurface = background;
					playerx = 1200;
				}
				else if (currentsurface == background3)
				{
					currentsurface = background2;
					playerx = 1200;
				}
				else if (currentsurface == background4)
				{
					currentsurface = background3;
					playerx = 1200;
					tryhardreset = true;
				}
				else if (currentsurface == background5)
				{
					currentsurface = background4;
					playerx = 1200;
				}
				else if (currentsurface == background6)
				{
					currentsurface = background5;
					playerx = 1200;
				}
				else if (currentsurface == background7)
				{
					yellowbarneyfirst6 = false;
					currentsurface = background6;
					playerx = 1200;
					playery = 30;
				}
				else if (currentsurface == background8)
				{
					currentsurface = background7;
					playerx = 1200;
				}
				else if (currentsurface == background9)
				{
					currentsurface = background8;
					playerx = 1200;
				}
				else if (currentsurface == background10)
				{
					currentsurface = background9;
					playerx = 1200;
				}
				else if (currentsurface == background11)
				{
					currentsurface = background10;
					playerx = 1200;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
				}
				else if (currentsurface == background17)
				{
					currentsurface = background16;
					playerx = 1200;
					playery = 550;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
				}
				else if (currentsurface == background18)
				{
					noground = false;
					currentsurface = background17;
					playerx = 1200;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
				}
				else if (currentsurface == background21)
				{
					currentsurface = background20;
					playerx = 1200;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
				}
				else if (currentsurface == background22)
				{
					playerx -= playervelx;
					//currentsurface = background21;
					//playerx = 1200;
					//for (int i = 0; i < 5; i++)
					//{
					//	bullets[i].out = 0;
					//}
				}
				else if (currentsurface == background23)
				{
					currentsurface = background22;
					playerx = 1200;
					for (int i = 0; i < 5; i++)
					{
						bullets[i].out = 0;
					}
				}
			}
			SDL_RenderPresent(grender);
		}
		
	}
	close();
	return 0;
}
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "Could not initialize SDL";
		success = false;
	}
	else
	{
		gwindow = SDL_CreateWindow("Heartman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenwidth, screenheight, SDL_WINDOW_SHOWN);//not resizable
		if (gwindow == 0)
		{
			cout << "could not create window";
			success = false;
		}
		else
		{
			gsurface = SDL_GetWindowSurface(gwindow);
			if (gsurface == 0)
			{
				cout << "could not upload surface";
				success = false;
			}
			else
			{
				int flags = IMG_INIT_PNG;
				if ((IMG_Init(flags) & flags) != flags)
				{
					cout << "failed to initialize png";
					success = false;
				}
				if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
				{
					cout << "failed to scale quality";
				}
				grender = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				SDL_SetRenderDrawColor(grender, 255, 255, 255, 255);

				TTF_Init();
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);	
			}
		}
	}
	return success;
}
bool loadmedia()
{
	
	bool success = true;
	SDL_Color textcolor = { 0,0,0 };
	SDL_Color textcolorwhite = { 255,255,255 };
	SDL_Color textcoloryellow = { 255,255,0 };
	SDL_Color textcolorblue = {0,0,255 };
	gfont = TTF_OpenFont("NewAmsterdam.ttf", 28);
	safespacemenu = loadtexture("whitebackground.PNG");
	menu1 = loadtexture("menu1.PNG");
	menu2 = loadtexture("menu2.PNG");
	background = loadtexture("barneyset.JPG");
	background2 = loadtexture("barneyset.JPG");
	background3 = loadtexture("barneyset.JPG");
	background4 = loadtexture("barneyset.JPG");
	background5 = loadtexture("barneyset2.JPG");
	background6 = loadtexture("barneyset2.JPG");
	background7 = loadtexture("barneyset2.JPG");
	background8 = loadtexture("barneyset2.JPG");
	background9 = loadtexture("backgroundrock.JPG");
	background10 = loadtexture("treebackground.JPG");
	background11 = loadtexture("treebackground.JPG");
	background12 = loadtexture("treebackground.JPG");
	background13 = loadtexture("treebackground.JPG");
	background14 = loadtexture("treebackground.JPG");
	background15 = loadtexture("treebackground.JPG");
	background16 = loadtexture("backgroundrock.JPG");
	background17 = loadtexture("cave4.JPG");
	background18 = loadtexture("cave4.JPG");
	background19 = loadtexture("cave4.JPG");
	background20 = loadtexture("backgroundrock.JPG");
	background21 = loadtexture("backgroundrock.JPG");
	background22 = loadtexture("throne1.JPG");
	background23 = loadtexture("backgroundrock.JPG");
	background24 = loadtexture("backgroundrock.JPG");
	background25 = loadtexture("backgroundrock.JPG");
	background26 = loadtexture("treebackground.JPG");
	
	sodaw = loadtexture("sodaw.PNG");
	shovel = loadseethroughwhite("shovel.JPG");
	luckfea = loadtexture("luckfea.PNG");
	mitchbar = loadseethroughwhite("mitchbar.PNG");
	content = loadtexture("content.PNG");
	robloxman = loadtexture("robloxman.PNG");
	robloxman2 = loadtexture("robloxman2.PNG");
	cx = loadtexture("cx.PNG");
	fire = loadtexture("fire.JPG");
	dramajones = loadtexture("dramajones.PNG");
	oldsodafeelsbadman = loadtexture("oldsodafeelsbadman.PNG");
	residentsleeper = loadtexture("feelsbadman.PNG");
	brosbeforehoes = loadtexture("brosbeforehoes.PNG");
	
	frostnova = loadtexture("frostnova.JPG");
	apechicken = loadseethroughwhite("chickenlegs.JPG");
	pissbottle = loadseethroughwhite("pissbottle.PNG");
	lava = loadtexture("lava2.PNG");
	rat = loadseethroughwhite("rat.JPG");
	
	evilbarneyhead = loadtexture("evilbarneyhead.PNG");
	
	bluelaser = loadseethroughwhite("bluelaser.JPG");
	miraw = loadtexture("miraw.PNG");
	mitchjones = loadseethroughwhite("mitchjones.PNG");
	cfour = loadseethroughwhite("c4.JPG");
	
	ball1 = loadseethroughwhite("dotblue.BMP");
	ball2 = loadseethroughwhite("dotyellow.BMP");
	brokenrecord = loadseethroughwhite("brokenrecord.PNG");
	ball3 = loadseethroughwhite("dotpurple.BMP");
	tigerwoods = loadtexture("tiger woods.JPG");
	arock = loadseethroughwhite("arock.PNG");
	
	arcane = loadseethroughwhite("arcane.PNG");
	dot = loadseethroughwhite("dot.BMP");
	opopie = loadseethroughwhite("opopie.JPG");
	sodadead = loadtexture("sodadead.JPG");
	fourhead = loadseethroughwhite("4head.JPG");
	cave = loadtexture("cave4.JPG");
	kgb = loadseethroughwhite("kgb.JPG");
	dorito = loadtexture("Dorito.PNG");
	smorc = loadseethroughwhite("smorc.PNG");
	hotpokket = loadtexture("hotpokket.PNG");
	princesspalace = loadseethroughwhite("princess castle.JPG");
	hangingbridge = loadseethroughwhite("hangingbridge.PNG");
	penguin = loadtexture("penguin.PNG");
	apple = loadseethroughwhite("apple.PNG");
	darkstone = loadtexture("darkstone2.JPG");
	ubuntu = loadseethroughwhite("ubuntu.PNG");
	sodanope = loadseethroughwhite("sodanope.PNG");
	windowsxp = loadseethroughwhite("windows.JPG");
	
	lilpump1 = loadseethroughwhite("lilpump.PNG");
	
	laserr = loadtexture("laserr.JPG");
	
	deathball = loadseethroughwhite("deathball.JPG");
	lilpump2 = loadseethroughwhite("lilpump2.PNG");
	lilpumpcurrent = lilpump1;
	wrist1 = loadseethroughwhite("wrist.JPG");
	patrickdick = loadtexture("patrickdick.PNG");
	wrist2 = loadseethroughwhite("wrist2.JPG");
	wrist3 = loadseethroughwhite("wrist3.JPG");
	explosion = loadtexture("explosion.JPG");
	bomb = loadseethroughwhite("bomb.JPG");
	anele = loadseethroughwhite("anele.JPG");
	uslogo = loadtexture("uslogo.JPG");
	missile = loadseethroughwhite("missile.JPG");
	demon = loadseethroughwhite("demon.JPG");
	barney = loadseethroughwhite("barney3.PNG");
	evilbarney = loadtexture("evilbarney.PNG");
	evilbarney2 = loadtexture("evilbarney2.PNG");
	missile2 = loadseethroughwhite("missile2.JPG");
	twitch = loadtexture("twitch.JPG");
	warning = loadtexture("warning.PNG");
	boshy = loadtexture("boshy.PNG");
	safespacetext = loadtext("This game contains some jokes and references from the internet... nothing is meant to be purposefully offensive or insulting by any means...", textcolor);
	credits1 = loadtext("Created by: Giovanni Miliziano",textcolorwhite);
	credits2 = loadtext("All images, sounds, and music generously borrowed from the world wide web",textcolorwhite);
	credits3 = loadtext("Heartman",textcoloryellow);
	scotttext = loadtext("Leave me be, i'm busy writing about debutantes", textcolor);
	brandontalk = loadtext("The crashing tide can't hide a guilty girl, with jealous hearts that start with gloss and curls",textcolor);
	roberttalk = loadtext("It's a perfect day for kiss and swell, for rip-zipping button-popping kiss and well...", textcolor);
	youshallnotpass = loadtext("You cannot pass, we are the knights of Robloxian!", textcoloryellow);
	boshytext = loadtext("Hey man press x or enter to shoot me",textcolor);
	textpage = loadtext("Welcome what is up dude...You are the heart man on this journey and I will tell you verbosely about his long, soporific, bookish tale... you know what nevermind just go out there and try not to get your heart broken!", textcolor);
	nextz = loadtext("Next", textcolor);
	instructions = loadtext("Q to reset, Press A and D and W or arrow keys to move left and right and jump...", textcolorwhite);
	barneytalk = loadtext("Welcome to Barney's World!", textcolorwhite);
	heart1 = loadseethrough("heart1.PNG");
	heart2 = loadseethrough("heart2.PNG");
	heart3 = loadseethrough("heart3.PNG");
	heart4 = loadseethrough("heart4.PNG");
	hole2 = loadtexture("hole2.JPG");
	
	dirt = loadtexture("dirt.JPG");
	rock = loadtexture("rock.JPG");
	ladder = loadseethroughwhite("ladder2.JPG");
	blooddrop = loadseethroughwhite("blooddrop.JPG");
	yellowbarney = loadseethroughwhite("barneyyello.PNG");
	yellowbarneyevil = loadtexture("barneyyelloevil.PNG");
	kid1 = loadseethroughwhite("kid1.JPG");
	kid2 = loadtexture("kid2.PNG");
	kid3 = loadseethroughwhite("kid3.JPG");
	arcaneblast = loadtexture("arcaneblast.JPG");
	hole = loadtexture("hole.JPG");
	stonewall = loadtexture("stonewall.JPG");
	chickenbucket = loadseethroughwhite("bucket.JPG");
	spike = loadseethroughwhite("spike2.PNG");
	TryHard = loadseethroughwhite("triihard.PNG");
	friedchicken = loadseethroughwhite("chicken.JPG");
	pyroblast = loadtexture("pyroblast.PNG");
	robert = loadseethroughwhite("robertsmith.JPG");
	brandon = loadseethroughwhite("brandon.JPG");
	scottfitzgerald = loadseethroughwhite("scottfitzgerald.JPG");
	stage = loadtexture("stage.JPG");

	perfectboy = Mix_LoadMUS("The Perfect Boy.wav");
	fleshandbones = Mix_LoadMUS("flesh and bone.wav");
	titlesong = Mix_LoadMUS("title.wav");
	barneytheme = Mix_LoadMUS("BarneyTheme.wav");
	allahmusic = Mix_LoadMUS("allah music.wav");
	scarymusic = Mix_LoadMUS("scary music.wav");
	mitchjonessong = Mix_LoadMUS("mitch music.wav");
	hundredonmywrist = Mix_LoadMUS("100 on my wrist.wav");
	pokigasm = Mix_LoadWAV("pokigasm1.wav");
	scream = Mix_LoadWAV("SCREAM.wav");
	barneyroar = Mix_LoadWAV("monster roar.wav");
	oof = Mix_LoadWAV("oof.wav");
	
	donttouchme = Mix_LoadWAV("dont touch me pzl.wav");
	thisisrape = Mix_LoadWAV("feministrage.wav");
	buttonpress = Mix_LoadWAV("button press.wav");
	doorbreak = Mix_LoadWAV("doorbreak.wav");
	macearrape = Mix_LoadWAV("Mac EARRAPE.wav");
	
	windowsearrape = Mix_LoadWAV("Windows XP startup earrape.wav");
	gunsound = Mix_LoadWAV("gun sound.wav");
	esketit = Mix_LoadWAV("esketit.wav");
	oohlilpump = Mix_LoadWAV("ooh lilpump.wav");
	lilpumplaugh = Mix_LoadWAV("lilpump laugh.wav");
	explosionsound = Mix_LoadWAV("Explosion.wav");
	missilesound = Mix_LoadWAV("Missile.wav");
	tigerwoodscheer = Mix_LoadWAV("tigerwoodscheer.wav");
	tigerwoodsnews = Mix_LoadWAV("tigerwoodsnews.wav");
	motel6 = Mix_LoadWAV("motel6.wav");
	hiyaa = Mix_LoadWAV("hiyaa.wav");
	omegashenron = Mix_LoadWAV("omegashenron.wav");
	kamehameha = Mix_LoadWAV("kamhameha.wav");
	peacebitch = Mix_LoadWAV("peace bitch.wav");
	getoutofmylevel = Mix_LoadWAV("getoutofmylevel.wav");
	mitchfunny = loadtexture("mitchfunny.JPG");
	apefight = Mix_LoadWAV("apefight.wav");
	fuckwithme = Mix_LoadWAV("fuckwithme.wav");
	hitme = Mix_LoadWAV("hitme.wav");
	fuckyouimdone = Mix_LoadWAV("fuck you im done.wav");
	getoutofmyface = Mix_LoadWAV("getoutofmyface.wav");
	sodamitchfight = Mix_LoadWAV("sodamitchfight.wav");
	sodascream = Mix_LoadWAV("sodascream.wav");
	pyah = Mix_LoadWAV("pyah.wav");
	usetheshovel = Mix_LoadWAV("usetheshovel.wav");
	mitchgetmeback = Mix_LoadWAV("mitchgetmeback.wav");
	mitchfight1 = Mix_LoadWAV("mitchfight1.wav");
	mitchfight2 = Mix_LoadWAV("mitchfight2.wav");
	mitchdonewithmira = Mix_LoadWAV("mitchdonewithmira.wav");
	mitchshowedupathouse = Mix_LoadWAV("mitchshowedupathouse.wav");
	mitchie = Mix_LoadWAV("mitchie.wav");
	earthquake = Mix_LoadWAV("earthquake.wav");
	mitchbrokenrecord = Mix_LoadWAV("mitchbrokenrecord.wav");
	patricklaugh = Mix_LoadWAV("patricklaugh.wav");
	mitchend = Mix_LoadWAV("mitchend.wav");
	notonwowsound = Mix_LoadWAV("notonwowsound.wav");
	oofear = Mix_LoadWAV("oofear.wav");
	barneydemon = Mix_LoadWAV("barneydemon.wav");
	barneyletsplaydie = Mix_LoadWAV("barneyletsplaydie.wav");
	barneyherewego = Mix_LoadWAV("barneyherewego.wav");
	barneywouldyoulike = Mix_LoadWAV("barneywouldyoulike.wav");
	barneythatwasfun = Mix_LoadWAV("barneythatwasfun.wav");
	barneyheyeveryone = Mix_LoadWAV("barneyheyeveryone.wav");
	barneydemon2 = Mix_LoadWAV("barneydemon2.wav");
	laser = Mix_LoadWAV("barneylaser.wav");
	barneysong = Mix_LoadMUS("barneysong.wav");
	chargelaser = Mix_LoadWAV("chargelaser.wav");
	cheers = Mix_LoadWAV("cheers.wav");

	currentheart = heart1;
	currentsurface = safespacemenu;//***************************menu1 safespacemenu
	return success;
}
SDL_Texture* loadtexture(string a)
{
	
	SDL_Texture* returntexture = 0;
	SDL_Surface* tempsurface = IMG_Load(a.c_str());
	//SDL_SetColorKey(tempsurface, SDL_TRUE, SDL_MapRGB(tempsurface->format, 255, 255, 255));
	returntexture = SDL_CreateTextureFromSurface(grender, tempsurface);
	SDL_FreeSurface(tempsurface);
	return returntexture;
}
SDL_Texture* loadtext(string s, SDL_Color textcolor)
{
	SDL_Surface* tempsurface = TTF_RenderText_Blended_Wrapped(gfont, s.c_str(), textcolor,screenwidth);
	SDL_Texture* returntexture;
	returntexture = SDL_CreateTextureFromSurface(grender, tempsurface);
	//cout << tempsurface->w << " " << tempsurface->h;
	//get width and height
	SDL_FreeSurface(tempsurface);
	return returntexture;
}
SDL_Texture* loadseethrough(string a)
{
	SDL_Texture* returntexture = 0;
	SDL_Surface* tempsurface = IMG_Load(a.c_str());
	SDL_SetColorKey(tempsurface, SDL_TRUE, SDL_MapRGB(tempsurface->format, 0, 0, 0)); //black
	returntexture = SDL_CreateTextureFromSurface(grender, tempsurface);
	SDL_FreeSurface(tempsurface);
	return returntexture;
}
SDL_Texture* loadseethroughwhite(string a)
{
	SDL_Texture* returntexture = 0;
	SDL_Surface* tempsurface = IMG_Load(a.c_str());
	SDL_SetColorKey(tempsurface, SDL_TRUE, SDL_MapRGB(tempsurface->format, 255, 255, 255)); //white
	returntexture = SDL_CreateTextureFromSurface(grender, tempsurface);
	SDL_FreeSurface(tempsurface);
	return returntexture;
}
void close()
{
	SDL_DestroyRenderer(grender);
	SDL_DestroyWindow(gwindow);
	gwindow = 0;
	SDL_FreeSurface(gsurface);
	gsurface = 0;
	SDL_DestroyTexture(menu1);
	SDL_DestroyTexture(menu2);
	Mix_FreeMusic(titlesong);

	Mix_Quit();
	SDL_Quit();
	IMG_Quit();
}
bool rectcollision(SDL_Rect a, SDL_Rect b)
{
	//20 for arms
	int leftA = a.x + 20;
	int rightA = a.x + a.w - 20;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftB = b.x;
	int rightB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (bottomA <= topB)
	{
		return false;
	}

	return true;
}
bool rectcollisionarray(rectz a[], int size, SDL_Rect heart)
{
	for (int i = 0; i < size; i++)
	{
		if (rectcollision(heart, a[i].plat))
		{
			if (a[i].hit == false)
			{
				return true;
			}
		}
	}
	return false;
	
}
void checkifontopofarray(rectz a[], int size,SDL_Rect heart)
{
	for (int i = 0; i < size; i++)
	{
		if (checkifontopof(heart, a[i].plat))
		{
			a[i].hit = true;
		}
		
	}
}
void checkifonsideofarray(rectz a[], int size, SDL_Rect heart)
{
	for (int i = 0; i < size; i++)
	{
		if (collisionsidebool(heart, a[i].plat))
		{
			a[i].hit = true;
		}

	}
}
bool checkifontopof(SDL_Rect a, SDL_Rect b)
{
	if (a.y + a.h > b.y && a.y + a.h < b.y + 10)
	{
		if (a.x > b.x - 60 && a.x + a.w < b.x + b.w + 60)
		{
	
			return true;
		}
	}
	return false;
}
bool collisionsidebool(SDL_Rect a, SDL_Rect b)
{
	if (checkcollision(a, b))
	{
		if (a.x + a.w < b.x + 50)
		{

			return true;
		}
		if (a.x>b.x + b.w - 50)
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}
char collisionside(SDL_Rect a, SDL_Rect b)
{
	if (checkcollision(a, b))
	{
		if (a.x + a.w < b.x+50)
		{
			
			return 'l';
		}
		if (a.x>b.x+b.w - 50)
		{
			return 'r';
		}
		return 'f';
	}
	else
	{
		return 'f';
	}
}
bool checkifontopofcorners(SDL_Rect a, SDL_Rect b)
{
	if (a.y + a.h > b.y && a.y + a.h < b.y + 10)
	{
		if (a.x < b.x - 60 && a.x + a.w > b.x + b.w + 60)
		{
			return true;
		}
	}
	return false;
}
bool checkcollision(SDL_Rect a, SDL_Rect b)
{
	bool ycheck = 0;
	bool xcheck = 0;
	if (a.y + a.h > b.y && a.y < b.y + b.h) //when it hits bottom of box
	{
		ycheck = true;
	}
	if (a.x + a.w > b.x && a.x < b.x + b.w) //when it hits bottom of box
	{
		xcheck = true;
	}
	if (xcheck == true && ycheck == true)
	{
		return true;
	}
	return false;
}
void move()
{
	playerx += playervelx;
	
	//playery += playervely;
	const Uint8* currentkeystate = SDL_GetKeyboardState(0);
	if (boshishoot == true && grabboshi == true)
	{
		//bullets[]
		if (bullets[currentbullet].out == 1)
		{

		}
		else
		{
			Mix_PlayChannel(-1, gunsound, 0);
			bullets[currentbullet].rect.x = playerx + 70;
			bullets[currentbullet].rect.y = playery + 10;
			bullets[currentbullet].out = 1;
			bullets[currentbullet].hit = 0;
			currentbullet++;
		}
		boshishoot = false;
	}
	if (currentbullet == 5)
	{
		currentbullet = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		if (bullets[i].rect.x > 1200)
		{
			bullets[i].out = 0;
		}
	}
	//if a bullet is out render it and increase it
	/*for (int i = 0; i < 5; i++)   **copy and paste this in render section
	{
		if (bullets[i].out == 1)
		{
			SDL_RenderCopy(grender, bullets[i].texture, 0, &bullets[i].rect);
			bullets[currentbullet].rect.x++;
		}
	}*/
	
	if (currentkeystate[SDL_SCANCODE_A] || currentkeystate[SDL_SCANCODE_LEFT])
	{
		heartcount++;
		//playerx -= 10;
		playerpos = 'a';
	}
	if (currentkeystate[SDL_SCANCODE_D] || currentkeystate[SDL_SCANCODE_RIGHT])
	{
		heartcount++;
		//playerx += 10;
		playerpos = 'd';
	}
	if (ladderon == true)
	{
	
		if (currentkeystate[SDL_SCANCODE_W] || currentkeystate[SDL_SCANCODE_UP])
		{
			playery -= 10;
		}
		if (currentkeystate[SDL_SCANCODE_S] || currentkeystate[SDL_SCANCODE_DOWN])
		{
			if (playery >= 535)
			{

			}
			else
			{
				playery += 10;
			}
			
		}
		ladderon = false;
	}
	else
	{
		if (currentkeystate[SDL_SCANCODE_W] || currentkeystate[SDL_SCANCODE_UP])
		{
		if (jumpagain == true)
		{
			jumpframes++;
			secondjump = true;
		}

		jumpagain = false;
		playerpos = 'w';
		}
		else
		{
			//heartcount = 0;
		}
		SDL_Rect heartman = { playerx,playery,75,75 };
		if (jumpagain == false && jumpframes > 0)
		{

			jump();
		}
		playery += gravityspeed;
		if (checkifontopof(heartman, ground))
		{
			if (noground == true)
			{

			}
			else
			{
				playery -= gravityspeed;
				jumpagain = true;
				secondjump = false;
			}
			
		}
	}
}
void jump() //30 , 9 //increments and check collision each time
{
	//25 and 11
	playery -= 25;
	jumpframes++;
	if (jumpframes == 11)
	{
		jumpframes = 0;
	}
}
void ballmove2()
{
	if (ballswitch == false)
	{
		ball1y = 100 * sin(((ball1upper*PI) / (180))) + 450;
		ball1upper += 10;
		ball1x -= 10;
		slowball1++;
	}
	else
	{
		ball1y = 100 * sin(((ball1upper*PI) / (180))) + 450;
		ball1upper += 5;
		ball1x += 10;
		slowball1++;
	}
	if (ball1x < 600)
	{
		ballswitch = true;
	}
	if (ball1x > 1100)
	{
		ballswitch = false;
	}
	//2nd one
	if (ball1switch == false)
	{
		ball11y = 100 * sin(((ball11upper*PI) / (180))) + 450;
		ball11upper += 10;
		ball11x -= 10;
		slowball1++;
	}
	else
	{
		ball11y = 100 * sin(((ball11upper*PI) / (180))) + 450;
		ball11upper += 5;
		ball11x += 10;
		slowball1++;
	}
	if (ball11x < 200)
	{
		ball1switch = true;
	}
	if (ball11x > 600)
	{
		ball1switch = false;
	}
}
void ballmove3()
{
	//ball1
	if (ballswitch == false)
	{
		ball3y = 100 * sin(((ball3upper*PI) / (180))) + 450;
		ball3upper += 10;
		ball3x -= 10;
		slowball1++;
	}
	else
	{
		ball3y = 100 * sin(((ball3upper*PI) / (180))) + 450;
		ball3upper += 5;
		ball3x += 10;
		slowball1++;
	}
	if (ball3x < 100)
	{
		ballswitch = true;
	}
	if (ball3x > 1100)
	{
		ballswitch = false;
	}

	//ball2
	int ydifference = 0;
	int xdifference = 0;
	if (ball2xswitch == false)
	{
		if (ball2xswitchfirsttime == false)
		{
			ball2x = math2number + 50 * sin(((5 * math2number)*PI) / (180)) + 200;
		}
		else
		{
			xdifference = (math2number + 50 * sin(((5 * math2number)*PI) / (180)) + 300) - (ball2xmovement);
			ball2x = ball2xmarkpoint + xdifference;
		}

	}
	if (ball2xswitch == true)
	{
		xdifference = (math2number + 50 * sin(((5 * math2number)*PI) / (180)) + 300) - (ball2xmovement);
		ball2x = ball2xmarkpoint - xdifference;
	}
	if (ball2yswitch == false)
	{
		if (ball2yswitchfirsttime == false)
		{

			ball2y = math2number + 50 * sin(((6 * math2number)*PI) / (180)) + 300;
		}
		else
		{
			ydifference = (math2number + 50 * sin(((6 * math2number)*PI) / (180)) + 300) - (ball2ymovement);
			ball2y = ball2ymarkpoint + ydifference;
		}

	}
	if (ball2yswitch == true)
	{
		ydifference = (math2number + 50 * sin(((6 * math2number)*PI) / (180)) + 300) - (ball2ymovement);
		ball2y = ball2ymarkpoint - ydifference;

	}

	math2number += 2;
	if (ball2x > 1200)
	{
		ball2xswitchfirsttime = true;
		ball2xswitch = true;
		ball2xmarkpoint = ball2x;
		ball2xmovement = (math2number - 1) + 50 * sin(((5 * (math2number - 1))*PI) / (180)) + 200;
	}
	if (ball2x < 200)
	{
		ball2xswitch = false;
		ball2xmarkpoint = ball2x;
		ball2xmovement = (math2number - 1) + 50 * sin(((5 * (math2number - 1))*PI) / (180)) + 200;
	}
	if (ball2y > 550)
	{
		ball2yswitchfirsttime = true;
		ball2yswitch = true;
		ball2ymarkpoint = ball2y;
		ball2ymovement = (math2number - 1) + 50 * sin(((6 * (math2number - 1))*PI) / (180)) + 300;
	}
	if (ball2y < 350)
	{
		ball2yswitch = false;
		ball2ymarkpoint = ball2y;
		ball2ymovement = (math2number - 1) + 50 * sin(((6 * (math2number - 1))*PI) / (180)) + 300;
	}
}
void ballmove4()
{
	//circle ball
	double radians = angle * (PI / 180);

	ball4y = ball4radius * sin(radians) + 350; //can be between 300-400
	ball4x = ball4radius * cos(radians) + 520; //can be between 300-400
	
	angle += 7;
	//cout << "x: " << ball4x << " y: " << ball4y << endl;

	//tryhard movement
	if (playerx > 300 && tryhardreset == true)
	{
		tryhardspawn = true;
	}
	if (tryhardspawn == true)
	{
		tryhardy--;
		tryhardy--;
		tryhardy--;
		if (tryhardy < 50)
		{
			chickeny--;
			chickeny--;
		}
	}
	if (tryhardy < -1000)
	{
		tryhardspawn = false;
		tryhardreset = false;
		tryhardy = 650;
	}
}
void ballmove5(droppingobject a[])
{
	if (blooddropcounter > 13)
	{
		SDL_RenderCopyEx(grender, a[blooddropcounter].texture, 0, &a[blooddropcounter].rect,headangle,NULL,SDL_FLIP_NONE);
		a[blooddropcounter].rect.y += 10;
		yellowbarneyfirst = false;
	}
	else if (blooddropcounter > 10)
	{
		if (blooddropcounter == 11)
		{
			SDL_RenderCopy(grender, a[blooddropcounter].texture, 0, &a[blooddropcounter].rect);
			a[blooddropcounter].rect.y += 10;
		}
		else
		{
			SDL_RenderCopyEx(grender, a[blooddropcounter].texture, 0, &a[blooddropcounter].rect, headangle, NULL, SDL_FLIP_NONE);
			a[blooddropcounter].rect.y += 10;
		}
		if (a[blooddropcounter].rect.y > screenheight / 2)
		{
			Mix_PlayChannel(-1, oof, 0);
			SDL_RenderCopyEx(grender, a[blooddropcounter + 1].texture, 0, &a[blooddropcounter + 1].rect,headangle,NULL,SDL_FLIP_NONE);
			a[blooddropcounter + 1].rect.y += 10;
		}
		if (a[blooddropcounter].rect.y++ > 600)
		{
			blooddropcounter++;
		}
	}
	else
	{
		SDL_RenderCopy(grender, a[blooddropcounter].texture, 0, &a[blooddropcounter].rect);
		a[blooddropcounter].rect.y+=10;
		if (a[blooddropcounter].rect.y > screenheight / 2)
		{
			SDL_RenderCopy(grender, a[blooddropcounter + 1].texture, 0, &a[blooddropcounter + 1].rect);
			a[blooddropcounter + 1].rect.y+=10;
		}
		if (a[blooddropcounter].rect.y++ > 600)
		{
			blooddropcounter++;
		}
	}
	headangle += 20;
	
}
void ballmove6(droppingobject a[]) //blooddropcounter6 framecount6
{
	
	if (hit[0] == false)
	{
		SDL_RenderCopy(grender, a[0].texture, 0, &a[0].rect);
		a[0].rect.y += 7;
	}

	if (a[0].rect.y > 600)
	{
		a[0].rect.y = 0;
		a[0].rect.x = (rand() % 800) + 100;
		hit[0] = true;
	}
	if (blooddropcounter6 > 0 && hit[1] == false)
	{
		SDL_RenderCopy(grender, a[1].texture, 0, &a[1].rect);
		a[1].rect.y += 7;
	}
	if (a[1].rect.y > 600)
	{
		a[1].rect.y = 0;
		a[1].rect.x = (rand() % 800) + 100;
		hit[1] = true;
	}
	if (blooddropcounter6 > 1 && hit[2] == false)
	{
		SDL_RenderCopy(grender, a[2].texture, 0, &a[2].rect);
		a[2].rect.y += 7;
	}
	if (a[2].rect.y > 600 )
	{
		a[2].rect.y = 0;
		a[2].rect.x = (rand() % 800) + 100;
		hit[2] = true;
	}
	if (blooddropcounter6 > 2 && hit[3] == false)
	{
		SDL_RenderCopy(grender, a[3].texture, 0, &a[3].rect);
		a[3].rect.y += 7;
	}
	if (a[3].rect.y > 600)
	{
		a[3].rect.y = 0;
		a[3].rect.x = (rand() % 800) + 100;
		hit[3] = true;
	}
	if (blooddropcounter6 > 3 && hit[4] == false)
	{
		SDL_RenderCopy(grender, a[4].texture, 0, &a[4].rect);
		a[4].rect.y += 7;
	}
	if (a[4].rect.y > 600)
	{
		a[4].rect.y = 0;
		a[4].rect.x = (rand() % 800) + 100;
		hit[4] = true;
	}
	if (blooddropcounter6 > 4 && hit[5] == false)
	{
		SDL_RenderCopy(grender, a[5].texture, 0, &a[5].rect);
		a[5].rect.y += 7;
	}
	if (a[5].rect.y > 600)
	{
		a[5].rect.y = 0;
		a[5].rect.x = (rand() % 800) + 100;
		hit[5] = true;
	}
	if (blooddropcounter6 > 5 && hit[6] == false)
	{
		SDL_RenderCopy(grender, a[6].texture, 0, &a[6].rect);
		a[6].rect.y += 7;
	}
	if (a[6].rect.y > 600)
	{
		a[6].rect.y = 0;
		a[6].rect.x = (rand() % 800) + 100;
		hit[6] = true;
	}
	if (blooddropcounter6 > 6 && hit[7] == false)
	{
		SDL_RenderCopy(grender, a[7].texture, 0, &a[7].rect);
		a[7].rect.y += 7;
	}
	if (a[7].rect.y > 600)
	{
		a[7].rect.y = 0;
		a[7].rect.x = (rand() % 800) + 100;
		hit[7] = true;
	}
	if (blooddropcounter6 > 7 && hit[8] == false)
	{
		SDL_RenderCopy(grender, a[8].texture, 0, &a[8].rect);
		a[8].rect.y+= 7;
	}
	if (a[8].rect.y > 600)
	{
		a[8].rect.y = 0;
		a[8].rect.x = (rand() % 800) + 100;
		hit[8] = true;
	}


	if (blooddropcounter6 == 8)
	{
		//onetime6 = true;
	}
		if (framecount6 == 20)
		{
			framecount6 = 0;
			blooddropcounter6++;
		}
		framecount6++;
		if (blooddropcounter6 % 8 == 0)
		{
			hit[0] = false;
		}
		if (blooddropcounter6 % 8 == 1)
		{
			hit[1] = false;
		}
		if (blooddropcounter6 % 8 == 2)
		{
			hit[2] = false;
		}
		if (blooddropcounter6 % 8 == 3)
		{
			hit[3] = false;
		}
		if (blooddropcounter6 % 8 == 4)
		{
			hit[4] = false;
		}
		if (blooddropcounter6 % 8 == 5)
		{
			hit[5] = false;
		}
		if (blooddropcounter6 % 8 == 6)
		{
			hit[6] = false;
		}
		if (blooddropcounter6 % 8 == 7)
		{
			hit[7] = false;
		}
}
void ballmove7()
{
	double radians = angle * (PI / 180);
	
	ball71y = ball7radius * sin(radians) + 85; //can be between 300-400
	ball71x = ball7radius * cos(radians) + 700; //can be between 300-400

	angle += 7;
	double radians7 = angle7 * (PI / 180);

	ball72y = ball7radius * sin(radians7) + 85; //can be between 300-400
	ball72x = ball7radius * cos(radians7) + 900; //can be between 300-400

	angle7 -= 7;
	
	spinangle += 1;
	if (shoottrihards == true)
	{
		if (trihardcounter == 8)
		{
			SDL_RenderCopy(grender, trihards[trihardcounter].texture, 0, &trihards[trihardcounter].rect);
			trihards[trihardcounter].rect.x -= 12;

			if (trihards[trihardcounter].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[trihardcounter + 1].texture, 0, &trihards[trihardcounter + 1].rect);
				trihards[trihardcounter + 1].rect.x -= 12;
			}
			if (trihards[trihardcounter + 1].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[0].texture, 0, &trihards[0].rect);
				trihards[0].rect.x -= 12;
			}
			if (trihards[trihardcounter].rect.x == 0)
			{
				trihardcounter++;
			}
		}
		else if (trihardcounter == 9)
		{
			SDL_RenderCopy(grender, trihards[trihardcounter].texture, 0, &trihards[trihardcounter].rect);
			trihards[trihardcounter].rect.x -= 12;

			if (trihards[trihardcounter].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[0].texture, 0, &trihards[0].rect);
				trihards[0].rect.x -= 12;
			}
			if (trihards[0].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[1].texture, 0, &trihards[1].rect);
				trihards[1].rect.x -= 12;
			}
			if (trihards[trihardcounter].rect.x == 0)
			{
				trihardcounter = 0;
			}
		}
		else
		{
			
			SDL_RenderCopy(grender, trihards[trihardcounter].texture, 0, &trihards[trihardcounter].rect);
			trihards[trihardcounter].rect.x -= 12;
			
			if (trihards[trihardcounter].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[trihardcounter + 1].texture, 0, &trihards[trihardcounter + 1].rect);
				trihards[trihardcounter + 1].rect.x -= 12;
			}
			if (trihards[trihardcounter+1].rect.x < 800)
			{
				SDL_RenderCopy(grender, trihards[trihardcounter + 2].texture, 0, &trihards[trihardcounter + 2].rect);
				trihards[trihardcounter + 2].rect.x -= 12;
			}
			if (trihards[trihardcounter].rect.x == 0)
			{
				trihardcounter++;
			}
		}
	
		


		for (int i = 0; i < 10; i++)
		{
			if (trihards[i].rect.x < 0)
			{
				if (i == 0)
				{
					firsttrihard = false;
				}
				int x = rand() % 2;
				if (x == 0)
				{
					trihards[i].rect.y = 425;
				}
				if (x == 1)
				{
					trihards[i].rect.y = 550;
				}
				trihards[i].rect.x = 1200;
			}
		}
	}
}
void ballmove8()//y be 420 to 585
{
	//ball1
	double radians = angle8 * (PI / 180);
	ball81y = ball8radius * sin(radians) + 510; //can be between 300-400
	ball81x = ball8radius * cos(radians) + 300; //can be between 300-400
	angle8 += 5;
	//ball2
	radians = angle82 * (PI / 180);
	ball82y = ball8radius * sin(radians) + 510; //can be between 300-400
	ball82x = ball8radius * cos(radians) + 600; //can be between 300-400
	angle82 -= 7;
	//ball3
	radians = angle83 * (PI / 180);
	ball83y = ball8radius * sin(radians) + 510; //can be between 300-400
	ball83x = ball8radius * cos(radians) + 900; //can be between 300-400
	angle83 += 8;

	//sjw2
	if (sjw82switch == false)
	{
		sjw82x += 10;
	}
	else if (sjw82switch == true)
	{
		sjw82x -= 10;
	}
	if (sjw82x == 1000)
	{
		sjw82switch = true;
	}
	else if (sjw82x == 200)
	{
		sjw82switch = false;
	}
	sjw82angle += 10;
	//sjw1
	//sjw81x sjw81y
	//y = mx + b y sjw81ltor  sjw82utod
	if (sjw81ltor == true)
	{
		sjw81x += 5;
		if (sjw81utod == true)
		{
			sjw81y = sjw81x + sjw81b;
		}
		else
		{
			sjw81y = -sjw81x + sjw81b;
		}
	}
	else
	{
		sjw81x -= 5;
		if (sjw81utod == true)
		{
			sjw81y = sjw81x + sjw81b;
		}
		else
		{
			sjw81y = -sjw81x + sjw81b;
		}
	}
	
	if (sjw81x >= 900)
	{
		sjw81ltor = false;
	}
	if (sjw81x <= 180)
	{
		sjw81ltor = true;
	}
	if (sjw81y <= 200)
	{
		
		if (sjw81ltor == true)
		{
			sjw81b = sjw81y - sjw81x;
			sjw81utod = true;
		}
		else
		{
			sjw81b = sjw81y + sjw81x;
			sjw81utod = false;
		}
	}
	if (sjw81y >= 380)
	{
		
		if (sjw81ltor == true)
		{
			sjw81b = sjw81y + sjw81x;
			sjw81utod = false;
		}
		else
		{
			sjw81b = sjw81y - sjw81x;
			sjw81utod = true;
		}
	}
	//walls red doors walls 1-5 1,2,1,3,1,4
	if (wall8counter % 180 < 90)
	{
		wall1red = true;
		wall2red = false;
	}
	if (wall8counter % 180 > 90)
	{
		wall2red = true;
		wall1red = false;
	}
	if (wall8counter % 180 < 60)
	{
		wall3red = true;
		wall4red = false;
	}
	if (wall8counter % 180 > 60)
	{
		wall3red = false;
		wall4red = true;
	}
	wall8counter += 2;

	//trihards-------
	if (shoottrihards8 == true)
	{
		if (trihardcounter == 8)
		{
			SDL_RenderCopy(grender, trihards8[trihardcounter].texture, 0, &trihards8[trihardcounter].rect);
			trihards8[trihardcounter].rect.x -= 8;

			if (trihards8[trihardcounter].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[trihardcounter + 1].texture, 0, &trihards8[trihardcounter + 1].rect);
				trihards8[trihardcounter + 1].rect.x -= 8;
			}
			if (trihards8[trihardcounter + 1].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[0].texture, 0, &trihards8[0].rect);
				trihards8[0].rect.x -= 8;
			}
			if (trihards8[trihardcounter].rect.x == 0)
			{
				trihardcounter++;
			}
		}
		else if (trihardcounter == 9)
		{
			SDL_RenderCopy(grender, trihards8[trihardcounter].texture, 0, &trihards8[trihardcounter].rect);
			trihards8[trihardcounter].rect.x -= 8;

			if (trihards8[trihardcounter].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[0].texture, 0, &trihards8[0].rect);
				trihards8[0].rect.x -= 8;
			}
			if (trihards8[0].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[1].texture, 0, &trihards8[1].rect);
				trihards8[1].rect.x -= 8;
			}
			if (trihards8[trihardcounter].rect.x == 0)
			{
				trihardcounter = 0;
			}
		}
		else
		{

			SDL_RenderCopy(grender, trihards8[trihardcounter].texture, 0, &trihards8[trihardcounter].rect);
			trihards8[trihardcounter].rect.x -= 8;

			if (trihards8[trihardcounter].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[trihardcounter + 1].texture, 0, &trihards8[trihardcounter + 1].rect);
				trihards8[trihardcounter + 1].rect.x -= 8;
			}
			if (trihards8[trihardcounter + 1].rect.x < 700)
			{
				SDL_RenderCopy(grender, trihards8[trihardcounter + 2].texture, 0, &trihards8[trihardcounter + 2].rect);
				trihards8[trihardcounter + 2].rect.x -= 8;
			}
			if (trihards8[trihardcounter].rect.x == 0)
			{
				trihardcounter++;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (trihards8[i].rect.x < 0)
			{
				if (i == 0)
				{
					firsttrihard = false;
				}
				int x = rand() % 2;
				if (x == 0)
				{
					trihards8[i].rect.y = 25;
				}
				if (x == 1)
				{
					trihards8[i].rect.y = 145;
				}
				trihards8[i].rect.x = 1200;
			}
		}
	}
	//smorc
	if (playerx > 1080 && smorcfall == false)
	{
		smorc8y = 170;
		smorcfall = true;
	}
	if (smorcfall == true)
	{
		smorc8y += 10;
	}
	//TRIHARD chase
	if (spawntrihard8 == true)
	{
		if (hittryhard == true)
		{

		}
		else
		{
			if (trihard8x < 1050 && trihard8y >= 400)
			{
				trihard8x += 4;
			}
			else if (trihard8x >= 1050 && trihard8y >= 190)
			{
				trihard8y -= 4;
			}
			else if (trihard8x > 45 && trihard8y >= 150 && trihard8y <= 500)
			{
				trihard8x -= 4;
			}
			else if (trihard8x <= 45 && trihard8y <= 500 && trihard8y >= 20)
			{
				trihard8y -= 4;
			}
			else
			{
				trihard8x += 4;
			}
		}
	}
		//twitch
		if (hittryhard == true)
		{
			trihardangle8 += 10;
			if (trihard8w < 0 && trihard8h < 0)
			{
				trihard8x = -100;
				trihard8y = -100;
				twitch8x += 3;
			}
			else
			{
				trihard8w -= 1;
				trihard8h -= 2;
			}
		}
		else
		{
			if (twitchalive == true)
			{
				twitch8x -= 3;
			}
		}
		
		
}
void ballmove16()
{
	if (greenbutton == true)//400 570
	{
		SDL_Rect lilpumpheal = { 900,20,lilpumphealth * 5,10 };
		if (lilpumphealth > 0)
		{
			SDL_SetRenderDrawColor(grender, 250, 0, 0, 0);
			SDL_RenderFillRect(grender, &lilpumpheal);
			
		}
		else
		{
			if (haltlilpump == false)
			{
				Mix_HaltMusic();
				haltlilpump = true;
			}
			
			
			lilpumpp5 = true;
			lilpumpp4 = false;
			SDL_Rect despawn = { -1000,-1000,25,25 };
			for (int i = 0; i < 50; i++)
			{
				chainz[i].rect = despawn;
			}
		}
		if (lilpumpx == -100)
		{
			Mix_PlayChannel(-1, oohlilpump, 0);
			lilpumpx = 0;
			lilpumpp1 = true;
			//initiate chainz
			for (int i = 0; i < 50; i++)
			{
				int random = rand() % 3;
				if (random == 0)
				{
					chainz[i].texture = wrist2;
				}
				if (random == 1)
				{
					chainz[i].texture = wrist1;
				}
				if (random == 2)
				{
					chainz[i].texture = wrist1;
				}
				
				chainz[i].rect = { -1000,-1000,1,1 };
				chainz[i].out = 0;
			}
		}
		
		if (lilpumpp1 == true)
		{
			if (lilpumpy > 500)
			{
				if (lilpumpx > 1100)
				{
					Mix_PlayChannel(-1, esketit, 0);
					lilpumpp2 = true;
					lilpumpp1 = false;
				}
				else
				{
					lilpumpx += 15;
				}
				
			}
			else
			{
				lilpumpy = lilpumpx + 170;
				lilpumpx += 7;
			}
		
		}
		else if (lilpumpp2 == true)
		{
			if (lilpumpx < 1)
			{
				lilpumpp2 = false;
				lilpumpp3 = true;
			}
			else
			{
				lilpumpx -= 15;
			}
		}
		else if (lilpumpp3 == true)
		{
			if (lilpumpx > 985)
			{
				lilpumpp3 = false;
				lilpumpp4 = true;
			}
			else
			{
				lilpumpx += 15;
			}
		}
		else if (lilpumpp4 == true)
		{
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(hundredonmywrist, 0);
			}
			
			
			if (lilpumpy < 100)
			{
				lilpumpup = false;
			}
			if (lilpumpy > 500)
			{
				lilpumpup = true;
			}
			if (lilpumpup == true)
			{
				lilpumpy -= 7;
			}
			else
			{
				lilpumpy += 7;
			}
			if (chainzcounter % chainzspeed == 0)
			{
				SDL_Rect newrect;
				newrect.x = lilpumpx;
				newrect.y = lilpumpy;
				newrect.h = 25;
				newrect.w = 25;
				chainz[currentchainz].out = 1;
				chainz[currentchainz].rect = newrect;
				chainz[currentchainz].b = chainz[currentchainz].rect.y - -.0003*pow(chainz[currentchainz].rect.x,2);
				currentchainz++;
			}
			for (int i = 0; i < 50; i++)
			{
				if (chainz[i].out == 1)
				{
					SDL_RenderCopy(grender, chainz[i].texture, 0, &chainz[i].rect);
					chainz[i].rect.y = -.0003*pow(chainz[i].rect.x,2) + chainz[i].b;
					chainz[i].rect.x -= 6;
				}
			}

			if (currentchainz == 50)
			{
				currentchainz = 0;
			}
			if (chainzcounter % 300 == 0)
			{
				if (chainzspeed <= 25)
				{
					chainzspeed = 40;
				}
				else
				{
					chainzspeed -= 4;
				}
				
			}
			chainzcounter++;
		}
		else if (lilpumpp5 == 1)
		{
			lilpumpcurrent = lilpump2;
			if (lilpumpw > 0)
			{
				if (playonce == 1)
				{
					Mix_PlayChannel(-1, lilpumplaugh, 0);
					playonce = 0;
				}
				lilpumpangle += 5;
				lilpumph -= 1;
				lilpumpw -= 1;
			}
			else
			{
				lilpumpx = -1000;
				lilpumpy = -1000;
				lilpumpp5 = 0;
			}
			

		}

		
	}
	if (whitebutton == true)
	{
		if (anelealive == 0)
		{
			if (haltallah == false)
			{
				Mix_HaltMusic();
				haltallah = true;
			}
			
		}
		else
		{
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(allahmusic, 0);
			}
			
		}
		if (anelex == -600)
		{
			SDL_Rect temp = { -500,-500,35,35 };
			for (int i = 0; i < 21; i++)
			{
				bombz[i].b = 150;
				bombz[i].hit = 0;
				bombz[i].out = 0;
				bombz[i].texture = bomb;
				bombz[i].rect = temp;
				
			}
			anelex = 450;
			aneley = 400;
			uslogox = 20;
			uslogoy = 545;
			uslogo2y = 545;
			uslogo2x = 900;
			rbutton1y = 535;
			rbutton2y = -100;
	
		}
		if (anelemoveup == 0)
		{
			aneley += 8;
		}
		else if(anelemoveup == 1)
		{
			aneley -= 8;
		}
		if (pausetimer < 390)
		{
			cfourx = 450;
		}
		if (pausetimer >= 390)
		{
			cfourx = 2000;
		}
		if (aneley > 450 && pausetimer < 390)
		{
			anelemoveup = 1;
		}
		if (aneley < 300 && pausetimer < 390)
		{
			anelemoveup = 0;
		}
		if (pausetimer > 390 && anelex == 450)
		{
			anelex = 600;
			aneley = 50;
			anelemoveup = 2;
		}
		if (press1 == 1)
		{
			if (press2 == 0)
			{
				rbutton1y = -100;
				rbutton2y = 535;
			}
		}
		if (press2 == 1)
		{
			rbutton1y = 535;
			rbutton2y = -100;
		}
		if (press3 == 1)
		{
			rbutton1y = -100;
			rbutton2y = -100;
			if (rockety == -1000)
			{
				Mix_PlayChannel(-1, missilesound, 0);
				rocketx = 30;
				rockety = 535;
			}
			if (anelealive == 0)
			{

			}
			else
			{
				rockety = -17 * sqrt(rocketx) + 500;
				rocketx += 5;
			}
			
		}
		if (anelealive == 0)
		{
			for (int i = 0; i < 21; i++)
			{
				bombz[i].rect = { -100,-100,1,1 };
			}
		}
		else
		{
			if (pausetimer < 390)
			{

			}
			else
			{
				if (bombzcounter % 35 == 0)
				{
					bombz[currentbomz].rect.x = 600;
					bombz[currentbomz].rect.y = 150;
					bombz[currentbomz].width = 0;
					bombz[currentbomz].out = 1;
					bombz[currentbomz].dir = 0;
					currentbomz++;
				}
				if (bombzcounter % 35 == 18)
				{
					bombz[currentbomz].rect.x = 600;
					bombz[currentbomz].rect.y = 150;
					bombz[currentbomz].width = 0;
					bombz[currentbomz].out = 1;
					bombz[currentbomz].dir = 1;
					currentbomz++;
				}
				if (bombzcounter % 35 == 26)
				{
					bombz[currentbomz].rect.x = 600;
					bombz[currentbomz].rect.y = 150;
					bombz[currentbomz].width = 0;
					bombz[currentbomz].out = 1;
					bombz[currentbomz].dir = 2;
					currentbomz++;
				}
				for (int i = 0; i < 21; i++)
				{
					if (bombz[i].rect.y > 600)
					{
						bombz[i].out = 0;
					}
					if (bombz[i].out == 1)
					{
						if (bombz[i].width == 0)
						{
							if (bombz[i].dir == 0)
							{
								int random = rand() % 4;
								if (random == 0)
								{
									bombz[i].width = .01;
									bombz[i].speed = 4;
								}
								if (random == 1)
								{
									bombz[i].width = .003;
									bombz[i].speed = 6;
								}
								if (random == 2)
								{
									bombz[i].width = .005;
									bombz[i].speed = 5;
								}
								if (random == 3)
								{
									bombz[i].width = .008;
									bombz[i].speed = 5;
								}
							}
							else if (bombz[i].dir == 1)
							{
								int random = rand() % 4;
								if (random == 0)
								{
									bombz[i].width = .01;
									bombz[i].speed = -4;
								}
								if (random == 1)
								{
									bombz[i].width = .003;
									bombz[i].speed = -6;
								}
								if (random == 2)
								{
									bombz[i].width = .005;
									bombz[i].speed = -5;
								}
								if (random == 3)
								{
									bombz[i].width = .008;
									bombz[i].speed = -5;
								}
							}
							else if (bombz[i].dir == 2)
							{
								int random = rand() % 3;
								if (random == 0)
								{
									bombz[i].width = .05;
									bombz[i].speed = 2;
								}
								if (random == 1)
								{
									bombz[i].width = .05;
									bombz[i].speed = -2;
								}
								if (random == 2)
								{
									bombz[i].width = 1;
									bombz[i].speed = 10;
								}
							}

						}
						SDL_RenderCopy(grender, bombz[i].texture, 0, &bombz[i].rect);
						if (bombz[i].width == 1)
						{
							bombz[i].rect.y += bombz[i].speed;
						}
						else
						{
							bombz[i].rect.y = bombz[i].width*pow((bombz[i].rect.x - 600), 2) + bombz[i].b;
							bombz[i].rect.x += bombz[i].speed;
						}

					}
				}
			
			if (currentbomz == 21)
			{
				currentbomz = 0;
			}
			bombzcounter++;
			}
		}
		pausetimer++;
		if (anelealive == 0)
		{

		}
		else
		{
			if (aneleright == 1)
			{
				aneleangle += 2;
			}
			else
			{
				aneleangle -= 2;
			}
			if (aneleangle > 30)
			{
				aneleright = 0;
			}
			if (aneleangle < -30)
			{
				aneleright = 1;
			}

		}
	
	}
	if (brownbutton == true)
	{
		if (tigerwoodshealth <= 0)
		{
			tigerwoods = loadtexture("scaryface.JPG");
			if (tigerh <= 0)
			{
				tigery = -10000;
				if (halttiger == 0)
				{
					Mix_HaltMusic();
					halttiger = 1;
				}
				
			}
			else
			{
				tigery--;
				tigerh--;
			}
			
		}
		if (Mix_PlayingMusic() == 0 && tigerwoodshealth > 0)
		{
			Mix_PlayMusic(scarymusic, 0);
		}
		if (tigercounter == 0)
		{
			Mix_PlayChannel(-1, tigerwoodscheer, 0);
		}
		if (tigercounter == 360)
		{
			Mix_PlayChannel(-1, tigerwoodsnews, 0);
		}
		if (tigercounter > 700 && tigerwoodshealth > 0)
		{
			tigerx--;
			tigery = 400;
		}
		tigercounter++;
	}
	if (greenbutton == 1 && whitebutton == 1 && brownbutton == 1)
	{
		
	}
	if (anelealive == 0 && lilpumphealth <= 0 && tigerwoodshealth <= 0)
	{
		wall16h--;
	}

}
void ballmove19()
{
	//mitch jones
	if (mitchjonesspawn == 1)
	{
		if (mitchfirsthalt == 1)
		{
			Mix_HaltChannel(-1);
			mitchfirsthalt = 0;
		}
		
		if (Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(mitchjonessong, 0);
		}
		if (mitchjonesx == -100)//initial position
		{
			mitchjonesx = 1000;
			mitchjonesy = 800;
		}

		if (stageone == 1)
		{
			if (mitchjonesy < 450 && bluelaserx == -200)
			{
				Mix_PlayChannel(-1, omegashenron, 0);
				mitchjoneslaser = 1;
			}
			if (mitchjonesy < 450)
			{

			}
			else
			{
				mitchjonesy--;
			}
			
		}
	if(stagetwo == 1)//move up and down and shoot laser and lasers fall from sky
	{
		if (stagethree == 1 && stagethreeonce == 1)
		{
			apechickenx = 400;
			apechickeny = 190;
			stagethreeonce = 0;
		}
		if (stagethree == 1)
		{
			//Mix_Volume(-1, 128);
			//play sounds
			if (apesoundnumber == 0)
			{
				if (Mix_Playing(-1) == 0)
				{
					Mix_PlayChannel(-1, apefight, 0);
					apesoundnumber = 1;
				}
			}
			if (apesoundnumber == 1)
			{
				if (Mix_Playing(-1) == 0)
				{
					Mix_PlayChannel(-1, fuckyouimdone, 0);
					apesoundnumber = 2;
				}
			}
			if (apesoundnumber == 2)
			{
				apechickenx -= 10;
				if (Mix_Playing(-1) == 0)
				{
					Mix_PlayChannel(-1, hitme, 0);
					apesoundnumber = 3;
				}
			}
			if (apesoundnumber == 3)
			{
				if (Mix_Playing(-1) == 0)
				{
					Mix_PlayChannel(-1, fuckwithme, 0);
					apesoundnumber = 4;
				}
			}
			if (apesoundnumber == 4)
			{
				mitchjonesy = 100;
				apechickeny = 450;
				apechickenx += 5;
				if (Mix_Playing(-1) == 0)
				{
					Mix_PlayChannel(-1, getoutofmyface, 0);
					apesoundnumber = 5;
				}
				if (apechickenx == 700)
				{
					mitchjoneslaser = 1;
				}
			}
			if (apesoundnumber == 5)
			{
				apechickenx = -300;
				apechickeny = -300;
				apesoundnumber = 6;
			}
			if (apesoundnumber == 6)
			{
				if (Mix_Playing(-1) == 0)
				{
					//reset all falling and shooting blasts 

					for (int i = 0; i < 30; i++)
					{
						fallingblast[i].hit = 0;
						fallingblast[i].out = 0;
						fallingblast[i].b = 0;
						fallingblast[i].rect = { -1000,-1000,50,50 };
						fallingblast[i].texture = arcaneblast;
					}
					for (int i = 0; i < 10; i++)
					{
						shootingblast[i].hit = 0;
						shootingblast[i].out = 0;
						shootingblast[i].b = 0;
						shootingblast[i].rect = { -1200,-1200,50,50 };
						shootingblast[i].texture = arcaneblast;
					}
					stagetwo = 0;
					stagethree = 0;
					stagefour = 1;
				}
			}

		}
		if (mitchjoneslaser == 1)//if hes doing laser dont move
		{

		}
		else
		{
			if (mitchmoveup == 1)
			{
				mitchjonesy -= 10;
			}
			if (mitchmovedown == 1)
			{
				mitchjonesy += 10;
			}
			if (mitchjonesy < 100)
			{
				mitchmovedown = 1;
				mitchmoveup = 0;
			}
			if (mitchjonesy > 525)
			{
				mitchmoveup = 1;
				mitchmovedown = 0;
			}
		}

		//initialize falling blasts
		if (stagetwofirsttime == 1)
		{
			for (int i = 0; i < 30; i++)
			{
				fallingblast[i].hit = 0;
				fallingblast[i].out = 0;
				fallingblast[i].b = 0;
				fallingblast[i].rect = { -1000,-1000,50,50 };
				fallingblast[i].texture = arcane;
			}
			for (int i = 0; i < 10; i++)
			{
				shootingblast[i].hit = 0;
				shootingblast[i].out = 0;
				shootingblast[i].b = 0;
				shootingblast[i].rect = { -1200,-1200,50,50 };
				shootingblast[i].texture = arcaneblast;
			}

			stagetwofirsttime = 0;
		}
		if (shootingblastcounter % 50 == 0 && apesoundnumber < 4)
		{
			shootingblast[currentshootingblast].out = 1;
			shootingblast[currentshootingblast].rect = { mitchjonesx,mitchjonesy,30,30 };

			currentshootingblast++;
			if (currentshootingblast == 10)
			{
				currentshootingblast = 0;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (shootingblast[i].out == 1)
			{
				SDL_RenderCopy(grender, shootingblast[i].texture, 0, &shootingblast[i].rect);
				shootingblast[i].rect.x -= 8;
			}
			if (shootingblast[i].rect.x < -200)
			{
				shootingblast[i].out = 0;
			}
		}
		if (blastcounter % randomcounter == 0 && apesoundnumber < 4)//when to spawn them blastcounter % randomcounter == 0 && apesoundnumber < 4
		{
			fallingblast[currentblast].out = 1;
			//5 spawn points
			int random = rand() % 10;
			int randomspeed = rand() % 3 + 4;
			switch (random)
			{
			case 0: fallingblast[currentblast].rect = { 100,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 1: fallingblast[currentblast].rect = { 200,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 2: fallingblast[currentblast].rect = { 300,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 3: fallingblast[currentblast].rect = { 400,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 4: fallingblast[currentblast].rect = { 500,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 5: fallingblast[currentblast].rect = { 150,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 6: fallingblast[currentblast].rect = { 250,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 7: fallingblast[currentblast].rect = { 350,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 8: fallingblast[currentblast].rect = { 450,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			case 9: fallingblast[currentblast].rect = { 225,0,30,30 }; fallingblast[currentblast].b = randomspeed; break;
			}
			currentblast++;
			if (currentblast == 30)
			{
				currentblast = 0;
			}
			randomcounter = rand() % 15 + 100; //40 - 50
			blastcounter = 0;

		}
		for (int i = 0; i < 30; i++)//loop to render move or reset
		{


			if (fallingblast[i].out == 1)//if its out we render and move
			{
				SDL_RenderCopy(grender, fallingblast[i].texture, 0, &fallingblast[i].rect);
				fallingblast[i].rect.y += fallingblast[i].b ;  //random speed

			}
			if (fallingblast[i].rect.y > 650)//if off screen reset
			{
				fallingblast[i].out = 0;
			}
		}
		if (stagethree == 1)//if ape is out no lasers
		{

		}
		else
		{
			if (shootlasercounter % randomlaser == 0)
			{
				mitchjoneslaser = 1;
				randomlaser = rand() % 200 + 450;
			}
		}
	
		if (shootlasercounter % 1000 == 0 && apebuttononce == 1)
		{
			apebuttonpress = 1;
			apebuttononce = 0;
		}
		blastcounter++;
		if (mitchjoneslaser == 1)
		{

		}
		else
		{
			shootingblastcounter++;
		}
		shootlasercounter++;
		


	}
		if (mitchjoneslaser == 1)//laser
		{
			if (bluelaserx == -200 && bluelasery == -200)
			{
				if (apesoundnumber == 4 || stagefive == 1)
				{

				}
				else
				{
					
					if (stageone == 1)
					{
						randomsong = 2;
					}
					else
					{
						randomsong = rand() % 3 + 5;
						randomsong = rand() % 3 + 5;
					}

					if (randomsong == 5)
					{
						Mix_PlayChannel(-1, kamehameha, 0);
						lasercharge = 200;
					}
					if (randomsong == 6)
					{
						//Mix_PlayChannel(-1, omegashenron, 0);
						lasercharge = 75;
					}
					if (randomsong == 7)
					{
						//Mix_PlayChannel(-1, hiyaa, 0);
						lasercharge = 75;
					}
				}
				bluelaserx = mitchjonesx - 50;
				bluelasery = mitchjonesy - 20;
			}
			if (bluelaserx < -1500 || bluelasery > 700)
			{
				bluelaserx = -200;
				bluelasery = -200;
				bluelaserw = 100;
				bluelaserh = 200;
				mitchjoneslaser = 0;
				if (stageone == 1)//at beggining once laser is over it starts the next phase
				{
					stageone = 0;
					stagetwo = 1;
				}
			}
			else
			{
				lasercharge--;
				if (lasercharge < 0)
				{
					if (stagethree == 1 || stagefive == 1 || stagesix == 1)
					{
					
						bluelaserx -= 10;
						
						bluelaserw += 10;
						bluelasery += 10;
					}
					else
					{
						if (randomsong == 6)
						{
							Mix_PlayChannel(-1, omegashenron, 0);
						}
						if (randomsong == 7)
						{
							Mix_PlayChannel(-1, hiyaa, 0);
						}
						bluelaserx -= 20;
						bluelaserw += 20;
						
					}
				}
			}
		}//laser
		if (stagefour == 1)
		{
			 bluelaserx = -200;
			 bluelasery = -200;
			if (mitchjoneslaser == 1)//if hes doing laser dont move
			{

			}
			else
			{
				if (mitchmoveup == 1)
				{
					mitchjonesy -= 10;
				}
				if (mitchmovedown == 1)
				{
					mitchjonesy += 10;
				}
				if (mitchjonesy < 100)
				{
					mitchmovedown = 1;
					mitchmoveup = 0;
				}
				if (mitchjonesy > 525)
				{
					mitchmoveup = 1;
					mitchmovedown = 0;
				}
			}

			//piss bottles
			if (stagefouronce == 1)
			{
				for (int i = 0; i < 15; i++)
				{
					pissbottles[i].b = 0;
					pissbottles[i].angle = 0;
					pissbottles[i].hit = 0;
					pissbottles[i].out = 0;
					pissbottles[i].speed = 0;
					pissbottles[i].width = 0;
					pissbottles[i].rect = { -500,-500,50,50 };
					pissbottles[i].texture = pissbottle;
				}
				stagefouronce = 0;
			}

			if (pissbottlecounter % 25 == 0)
			{
				pissbottles[currentpissbottle].angle = 0;
				int random = rand() % 4;
				if (random == 0)
				{
					pissbottles[currentpissbottle].addedwidth = 200;
					pissbottles[currentpissbottle].hit = 0;//hit means if the height is -100 or not
				}
				if (random == 1)
				{
					pissbottles[currentpissbottle].addedwidth = 400;
					pissbottles[currentpissbottle].hit = 0;
				}
				if (random == 2)
				{
					pissbottles[currentpissbottle].addedwidth = 200;
					pissbottles[currentpissbottle].hit = 1;
				}
				if (random == 2)
				{
					pissbottles[currentpissbottle].addedwidth = 50;
					pissbottles[currentpissbottle].hit = 0;
				}
				pissbottles[currentpissbottle].out = 1;
				pissbottles[currentpissbottle].rect = { mitchjonesx,mitchjonesy, 30, 30 };
				pissbottles[currentpissbottle].b = mitchjonesy;
				pissbottles[currentpissbottle].width = mitchjonesx;
				// this can represent different angle pissbottles[currentpissbottle].b = 1;

				currentpissbottle++;
				if (currentpissbottle == 15)
				{
					currentpissbottle = 0;
				}
			}
			for (int i = 0; i < 15; i++)
			{

				if (pissbottles[i].out == 1)
				{
					SDL_RenderCopyEx(grender, pissbottles[i].texture, 0, &pissbottles[i].rect, pissbottles[i].angle, 0, SDL_FLIP_NONE);
					pissbottles[i].angle += 10;

					//good ones .001, +100 or +200, -10 (sideways)|| .001, +100 or +400, -10, - 0 (higher)|| .001, +100 or +400, -10, - 100 (highest)
					//change position
					if (pissbottles[i].hit == 0)
					{
						pissbottles[i].rect.y = .001 * pow((pissbottles[i].rect.x + pissbottles[i].addedwidth) - pissbottles[i].width, 2) + pissbottles[i].b - 50;
					}
					else
					{
						pissbottles[i].rect.y = .001 * pow((pissbottles[i].rect.x + pissbottles[i].addedwidth) - pissbottles[i].width, 2) + pissbottles[i].b - 100;
					}
					pissbottles[i].rect.x -= 10;
				}
				if (pissbottles[i].rect.y > 650)
				{
					pissbottles[i].out = 0;
				}
			}
			if (pissbottlecounter % 1300 == 0)
			{
				sodabuttonpress = 1;
			}
			pissbottlecounter++;
			SDL_Rect bigbottle = { 275,162,100,100 };
			SDL_RenderCopy(grender, pissbottle, 0, &bigbottle);

		}
		
		if (stagefive == 1)
		{
			if (stagefiveonce == 1)
			{
				sodax = 250;
				soday = 300;
				shovelx = 275;
				shovely = 162;
				stagefiveonce = 0;
				sodacirclex = ((sodax + (sodax + 100)) / 2);
				sodacircley = ((soday + (soday + 100)) / 2);
				for (int i = 0; i < 15; i++)
				{
					dramashots[i].b = 0;
					dramashots[i].hit = 0;
					dramashots[i].out = 0;
					dramashots[i].rect = { -500,-500,100,20 };
					dramashots[i].texture = 0;
				}
			}
			if (sodarun == 1)
			{
				sodax += 5;
				shovelgrab = 0;
				shovelx = -544;
				shovely = -544;
				if (sodax > 800 && sodax < 806)
				{
					mitchjoneslaser = 1;
					Mix_PlayChannel(-1, peacebitch, 0);
				}
				if (sodax > 850)
				{
					if (sodaruncounter == 0)
					{
						sodax = 2000;
						sodaruncounter = 1;
					}
					if (sodax > 2200)
					{
						stagefive = 0;
						stagesix = 1;
					}
					
				}
			}
			else
			{
				if (Mix_Playing(-1) == 0)
				{
					if (sodacurrentsong == 1)
					{
						Mix_PlayChannel(-1, sodamitchfight, 0);
						sodacurrentsong = 2;
					}
					
				}
				
				if (dramashotcounter % 75 == 0)
				{
					//slope is width
					//spawn on a random point on a circle
					int randomangle;
					bool getangle = 1;
					while (getangle == 1)
					{
						randomangle = rand() % 360;
						if (randomangle >= 70 && randomangle <= 110)
						{

						}
						else if (randomangle >= 250 && randomangle <= 290)
						{

						}
						else
						{
							getangle = 0;
						}
					}
					double radian = (3.14 * randomangle) / 180;
					dramashots[currentdrama].rect.x = (cos(radian) * sodacircleradius) + sodacirclex;
					dramashots[currentdrama].rect.y = (sin(radian) * sodacircleradius) + sodacircley;
					if (dramashots[currentdrama].rect.x < sodacirclex)
					{
						dramashots[currentdrama].b = -1;
					}
					if (dramashots[currentdrama].rect.x > sodacirclex)
					{
						dramashots[currentdrama].b = 1;
					}
					if (dramashots[currentdrama].rect.x == sodacirclex)
					{
						dramashots[currentdrama].b = 0;
					}
					//added width is speed this breaks circle into 4 vertical lines and each one has different speed
					if (dramashots[currentdrama].rect.x >= sodacirclex + sodacircleradius / 2)
					{
						dramashots[currentdrama].addedwidth = 3;
					}
					if (dramashots[currentdrama].rect.x < sodacirclex + sodacircleradius / 2 && dramashots[currentdrama].rect.x > sodacirclex)
					{
						dramashots[currentdrama].addedwidth = .5;
					}
					if (dramashots[currentdrama].rect.x <= sodacirclex - sodacircleradius / 2)
					{
						dramashots[currentdrama].addedwidth = 3;
					}
					if (dramashots[currentdrama].rect.x > sodacirclex - sodacircleradius / 2 && dramashots[currentdrama].rect.x <= sodacirclex)
					{
						dramashots[currentdrama].addedwidth = .5;
					}
					//find slope
					dramashots[currentdrama].width = (dramashots[currentdrama].rect.y - sodacircley) / (dramashots[currentdrama].rect.x - sodacirclex);


					int texture = rand() % 7;
					switch (texture)
					{
					case 0: dramashots[currentdrama].texture = luckfea; break;
					case 1: dramashots[currentdrama].texture = content; break;
					case 2: dramashots[currentdrama].texture = cx; break;
					case 3: dramashots[currentdrama].texture = dramajones; break;
					case 4: dramashots[currentdrama].texture = oldsodafeelsbadman; break;
					case 5: dramashots[currentdrama].texture = residentsleeper; break;
					case 6: dramashots[currentdrama].texture = brosbeforehoes; break;
					}
					dramashots[currentdrama].out = 1;
					currentdrama++;
					if (currentdrama == 15)
					{
						currentdrama = 0;
					}
				}

				for (int i = 0; i < 15; i++)
				{
					if (dramashots[i].out == 1)
					{
						SDL_RenderCopy(grender, dramashots[i].texture, 0, &dramashots[i].rect);
						//line to center
						//change position
						//change of y position
						dramashots[i].rect.y = (dramashots[i].width * dramashots[i].rect.x) - (dramashots[i].width * sodacirclex) + sodacircley;

						//change of x position
						if (dramashots[i].b == -1)
						{
							dramashots[i].rect.x += dramashots[i].addedwidth;
						}
						else if (dramashots[i].b == 1)
						{
							dramashots[i].rect.x -= dramashots[i].addedwidth;
						}
						else if (dramashots[i].b == 0)
						{

						}
					}
				}
				if (dramashotcounter % 1300 == 0)
				{
					sodarun = 1;
					Mix_PlayChannel(-1, pyah, 0);
					
					for (int i = 0; i < 15; i++)
					{
						dramashots[i].b = 0;
						dramashots[i].hit = 0;
						dramashots[i].out = 0;
						dramashots[i].rect = { -500,-500,100,20 };
						dramashots[i].texture = 0;
					}
				}
				dramashotcounter++;
			}

			if (sodalife < 1)
			{
				if (bottleonce == 1)
				{
					Mix_PlayChannel(-1, sodascream, 0);
					giantbottlex = 50;
					giantbottley = 0;
					bottleonce = 0;
				}
				giantbottley += 3;


			}
			}
			if (stagesix == 1)
			{
				if (stagesixonce == 1)//initialize
				{
					//bluelaserx = -200;
					//bluelasery = -200;
					mitchjonesx = 1200;
					mitchjonesy = 300;
					stagesixonce = 0;
					for (int i = 0; i < 15; i++)
					{
						pyroblasts[i].texture = pyroblast;
						pyroblasts[i].rect = { -500,-500,30,30 };
						pyroblasts[i].out = 0;
						pyroblasts[i].b = 0;
					}
				}
				//mitch movement
				double radians = (3.14*mitchcircleangle) / 180;
				//x = radius * cos(radian - offset) + offset
				//y = radius * sin(radian - offset) + offset
				//center is (300,300)
				mitchjonesx = 400 * cos(radians) + 250;
				mitchjonesy = 400 * sin(radians) + 350;
				mitchcircleangle += 3;
				
				if (pyroblastcounter % randomcounter == 0)
				{
					pyroblasts[currentpyroblast].out = 1;
					pyroblasts[currentpyroblast].rect = { mitchjonesx,mitchjonesy + 50,10,10 };
					//center is (250,350) radius is 400
					//-150 to 650 and 250 as center
					//split up into 8 100s
					//the b value is .width
					pyroblasts[currentpyroblast].addedwidth = playerx;
					pyroblasts[currentpyroblast].width = playery;

					pyroblasts[currentpyroblast].angle = (playery - mitchjonesy) / (playerx - mitchjonesx);
					/*int randomslope = rand() % 3;
					if (randomslope == 0)
					{
						pyroblasts[currentpyroblast].angle = 0;
					}
					if (randomslope == 1)
					{
						pyroblasts[currentpyroblast].angle = 1;
					}
					if (randomslope == 2)
					{
						pyroblasts[currentpyroblast].angle = -1;
					}*/
					if (pyroblasts[currentpyroblast].rect.x < -50 && pyroblasts[currentpyroblast].rect.x >= -150)
					{
						pyroblasts[currentpyroblast].b = 1;
						pyroblasts[currentpyroblast].speed = 2;
					}
					if (pyroblasts[currentpyroblast].rect.x >= -50 && pyroblasts[currentpyroblast].rect.x < 50)
					{
						pyroblasts[currentpyroblast].b = 1;
						pyroblasts[currentpyroblast].speed = 2;
					}
					if (pyroblasts[currentpyroblast].rect.x >= 50 && pyroblasts[currentpyroblast].rect.x < 150)
					{
						pyroblasts[currentpyroblast].b = 1;
						pyroblasts[currentpyroblast].speed = 1;
					}
					if (pyroblasts[currentpyroblast].rect.x >= 150 && pyroblasts[currentpyroblast].rect.x < 250)
					{
						pyroblasts[currentpyroblast].b = 1;
						pyroblasts[currentpyroblast].speed = 1;
					}
					if (pyroblasts[currentpyroblast].rect.x < 250 == 250)
					{
						pyroblasts[currentpyroblast].b = 0;
					}
					if (pyroblasts[currentpyroblast].rect.x > 250 && pyroblasts[currentpyroblast].rect.x < 350)
					{
						pyroblasts[currentpyroblast].b = -1;
						pyroblasts[currentpyroblast].speed = -1;
					}
					if (pyroblasts[currentpyroblast].rect.x >= 350 && pyroblasts[currentpyroblast].rect.x < 450)
					{
						pyroblasts[currentpyroblast].b = -1;
						pyroblasts[currentpyroblast].speed = -1;
					}
					if (pyroblasts[currentpyroblast].rect.x >= 450 && pyroblasts[currentpyroblast].rect.x < 550)
					{
						pyroblasts[currentpyroblast].b = -1;
						pyroblasts[currentpyroblast].speed = -2;
					}
					if (pyroblasts[currentpyroblast].rect.x >= 550 && pyroblasts[currentpyroblast].rect.x <= 650)
					{
						pyroblasts[currentpyroblast].b = -1;
						pyroblasts[currentpyroblast].speed = -2;
					}
					
					randomcounter = rand() % 15 + 35;
					pyroblastcounter = 0;
					currentpyroblast++;
					if (currentpyroblast == 15)
					{
						currentpyroblast = 0;
					}

				}
				//cout << "mitchjonesx" << mitchjonesx << endl;
				//pyroblasts render and move
				for (int i = 0; i < 15; i++)
				{
					if (pyroblasts[i].out == 1)
					{
						SDL_RenderCopy(grender, pyroblasts[i].texture, 0, &pyroblasts[i].rect);
						pyroblasts[i].rect.y = (pyroblasts[i].angle * pyroblasts[i].rect.x) - ((pyroblasts[i].angle * pyroblasts[i].addedwidth)) + pyroblasts[i].width;
						if (pyroblasts[i].b == -1)
						{
							pyroblasts[i].rect.x += pyroblasts[i].speed;
						}
						if (pyroblasts[i].b == 1)
						{
							pyroblasts[i].rect.x += pyroblasts[i].speed;
						}
						if (pyroblasts[i].b == 0)
						{
							pyroblasts[i].rect.x += 0;
						}



					}
					if (pyroblasts[i].rect.y < 0 || pyroblasts[i].rect.y > 650)
					{
						pyroblasts[i].out = 0;
					}

				}
				
				if (stagesixendcounter % 1000 == 0)
				{
					Mix_PlayChannel(-1, mitchshowedupathouse, 0);
					mitchfight11 = 1;
				}
				if (Mix_Playing(-1) == 0 && mitchfight11 == 1)
				{
					Mix_PlayChannel(-1, earthquake, 0);
					mitchfight11 = 0;
				}
				if (stagesixendcounter % 1300 == 0)
				{
					//Mix_PlayChannel(-1, earthquake, 0);
					for (int i = 0; i < 15; i++)
					{
						pyroblasts[i].texture = pyroblast;
						pyroblasts[i].rect = { -500,-500,30,30 };
						pyroblasts[i].out = 0;
						pyroblasts[i].b = 0;
					}
					stagesix = 0;
					stageseven = 1;
					mitchjonesx = 1000;
					mitchjonesy = 101;
				}
				pyroblastcounter++;
				stagesixendcounter++;


			}
			if (stageseven == 1)
			{
				if (stagesevenonce == 1)
				{
					Mix_PlayChannel(-1, mitchfight1, 0);
					mitchjonesx = 1000;
					mitchjonesy = 101;
					mirax = 800;
					miray = mitchjonesy; 
					kgbx = 0;
					kgby = 300;
					for (int i = 0; i < 10; i++)
					{
						brokenrecords[i].texture = brokenrecord;
						brokenrecords[i].rect = { -200,-200,30,30 };
					}
					for (int i = 0; i < 5; i++)
					{
						fallingrocks[i].texture = arock;
						fallingrocks[i].rect = { -600,-600,40,40 };
					}
					for (int i = 0; i < 5; i++)
					{
						fallingrockhelp[i].texture = warning;
						fallingrockhelp[i].rect = { -600,-600,40,40 };
						fallingrockhelp[i].out = 0;
					}
					for (int i = 0; i < 10; i++)
					{
						miraplatforms[i] = { -500,-500,75,10 };
					}

					stagesevenonce = 0;
				}
				
				if (Mix_Playing(-1) == 0 && mirafight1 == 1)
				{
					Mix_PlayChannel(-1, mitchfight2, 0);
					mirafight1 = 0;
				}
				else if (Mix_Playing(-1) == 0 && mirafight2 == 1)
				{
					Mix_PlayChannel(-1, mitchdonewithmira, 0);
					mirafight2 = 0;
				}
				if (mitchmove == 1)
				{
					if (mitchmoveup == 1)
					{
						mitchjonesy -= 10;
					}
					if (mitchmovedown == 1)
					{
						mitchjonesy += 10;
					}
					if (mitchjonesy < 100)
					{
						mitchmovedown = 1;
						mitchmoveup = 0;
					}
					if (mitchjonesy > 525)
					{
						mitchmoveup = 1;
						mitchmovedown = 0;
					}
				}
				miray = mitchjonesy;
				//kgb movement
				if (miragone == 0)
				{
					if (kgbgoleft == 1)
					{
						kgbx -= kgbspeed;
						kgby = kgbamplitude * cos(.01 * kgbx) + 300;
					}
					if (kgbgoright == 1)
					{
						kgbx += kgbspeed;
						kgby = kgbamplitude * cos(.01 * kgbx) + 300;
					}
					if (kgbx > 750 && kgbgoright == 1)
					{
						kgbgoleft = true;
						kgbgoright = false;
						kgbamplitude = rand() % 250 + 50;

						int randumperiod = rand() % 3 + 2;
						kgbspeed = randumperiod;

					}
					if (kgbx < 0 && kgbgoleft == 1)
					{
						kgbgoright = true;
						kgbgoleft = false;
						kgbamplitude = rand() % 250 + 50;

						int randumperiod = rand() % 3 + 2;
						kgbspeed = randumperiod;
					}
				}
				else
				{
					if (miraplatformcounter % 100 == 0)
					{
						brokenrecords[currentbrokenrecord].rect = { mitchjonesx,mitchjonesy,40,40 };


						currentbrokenrecord++;
						if (currentbrokenrecord == 10)
						{
							currentbrokenrecord = 0;
						}
					}
					for (int i = 0; i < 10; i++)
					{
						SDL_RenderCopy(grender, brokenrecords[i].texture, 0, &brokenrecords[i].rect);
						brokenrecords[i].rect.x -= 5;
					}
				}
				if (mitchdead == 1)
				{
					if (platformy <= 585)
					{
						
						stageseven = 0;
						stageeight = 1;
						for (int i = 0; i < 10; i++)
						{
							brokenrecords[i].texture = brokenrecord;
							brokenrecords[i].rect = { -200,-200,30,30 };
						}
						for (int i = 0; i < 5; i++)
						{
							fallingrocks[i].texture = arock;
							fallingrocks[i].rect = { -600,-600,40,40 };
						}
						for (int i = 0; i < 5; i++)
						{
							fallingrockhelp[i].texture = warning;
							fallingrockhelp[i].rect = { -600,-600,40,40 };
							fallingrockhelp[i].out = 0;
						}
						for (int i = 0; i < 10; i++)
						{
							miraplatforms[i] = { -500,-500,75,10 };
						}
					}
					else
					{
						platformy -= 4;
						miraplatformcounter = 1;
						mitchmove = 0;
					}
					
				}
				if (plat3y < 800)
				{
					platformy += 1;
					plat1y += 1;
					plat2y += 1;
					plat3y += 1;
				}
				if (miramove == 1)
				{
					mirax += 8;
				}
				if (miraplatformcounter % 1800 == 0 && mirax == 800)
				{
					miramove = 1;
					mitchmove = 0;
					mirax = -50;
				}
				if (miraplatformcounter % 150 == 0)
				{
					fallingrocks[currentrock].rect.y = -200;
					int randomrock = rand() % 700 + 30;
					fallingrocks[currentrock].rect.x = randomrock;
					fallingrockhelp[currentrock].rect.y = 0;
					fallingrockhelp[currentrock].rect.x = randomrock;
					fallingrockhelp[currentrock].out = 1;
					currentrock++;
					if (currentrock == 5)
					{
						currentrock = 0;
					}
				}
				for (int i = 0; i < 5; i++)
				{
					SDL_RenderCopy(grender, arock, 0, &fallingrocks[i].rect);
					fallingrocks[i].rect.y += 6;
					if (fallingrockhelp[i].out == 1)
					{
						SDL_RenderCopy(grender, warning, 0, &fallingrockhelp[i].rect);
					}
					if (rectcollision(fallingrockhelp[i].rect, fallingrocks[i].rect))
					{
						fallingrockhelp[i].out = 0;
					}
					
				}
				if (miraplatformcounter % 60 == 0)
				{
					bool getnumber = 1;
					int random = 0;
					miraplatforms[currentmiraplatform].y = 0;
					while (getnumber == 1)
					{
						random = rand() % 700 + 30;
						if (random >= 30 && random < 205)
						{
							miraplatformx1count++;
							if (miraplatformx1count >= 2)
							{
								getnumber = 1;
							}
							else
							{
								getnumber = 0;
							}
							miraplatformx2count = 0;
							miraplatformx3count = 0;
							miraplatformx4count = 0;
						}
						else if (random >= 205 && random < 380)
						{
							miraplatformx2count++;
							if (miraplatformx2count >= 2)
							{
								getnumber = 1;
							}
							else
							{
								getnumber = 0;
							}
							miraplatformx1count = 0;
							miraplatformx3count = 0;
							miraplatformx4count = 0;
						}
						else if (random >= 380 && random > 555)
						{
							miraplatformx3count++;
							if (miraplatformx3count >= 2)
							{
								getnumber = 1;
							}
							else
							{
								getnumber = 0;
							}
							miraplatformx1count = 0;
							miraplatformx2count = 0;
							miraplatformx4count = 0;
						}
						else if (random >= 555)
						{
							miraplatformx4count++;
							if (miraplatformx4count >= 2)
							{
								getnumber = 1;
							}
							else
							{
								getnumber = 0;
							}
							miraplatformx1count = 0;
							miraplatformx2count = 0;
							miraplatformx3count = 0;
						}
					
					}
					miraplatforms[currentmiraplatform].x = random;



					
					currentmiraplatform++;
					if (currentmiraplatform == 10)
					{
						currentmiraplatform = 0;
					}
				}
				//move everyone
				for (int i = 0; i < 10; i++)
				{
					miraplatforms[i].y += 2;
				}
				miraplatformcounter++;
				if (miragone == 1)
				{
					if (Mix_Playing(-1) == 0 && brokenrecordsound == 1)
					{
						Mix_PlayChannel(-1, mitchbrokenrecord, 0);
						brokenrecordsound = 0;
					}
					if (Mix_Playing(-1) == 0 && notonwow == 1)
					{
						Mix_HaltChannel(-1);
						Mix_PlayChannel(-1, notonwowsound, 0);
						notonwow = 0;
					}
				}


			}//stage 7
			if (stageeight == 1)
			{
				if (stageeightonce == 1)
				{
					for (int i = 0; i < 5; i++)
					{
						patricks[i].texture = patrickdick;
						patricks[i].rect = { -500,-500,75,75 };
						patricks[i].out = 0;
					}

					stageeightonce = 0;

				}
				if (patrickcounter % 1000 == 0 && patricky == -1000)
				{
					patrickx = 1200;
					patricky = 100;
					patrickmove = 1;
					Mix_PlayChannel(-1, patricklaugh, 0);
				}
				if (patrickmove == 1)
				{
					patrickx -= 1;
				}
				if (patrickcounter % 100 == 0)
				{
					patricks[currentpatrick].rect.x = 1200;
					int random = rand() % 3;
					if (random == 0)
					{
						patricks[currentpatrick].rect.y = 500;
					}
					if (random == 1)
					{
						patricks[currentpatrick].rect.y = 400;
					}
					if (random == 2)
					{
						patricks[currentpatrick].rect.y = 500;
					}
					
					patricks[currentpatrick].out = 1;


					currentpatrick++;
					if (currentpatrick == 5)
					{
						currentpatrick = 0;
					}
				}
				for (int i = 0; i < 5; i++)
				{
					if (patricks[i].out == 1)
					{
						SDL_RenderCopy(grender, patricks[i].texture, 0, &patricks[i].rect);
						patricks[i].rect.x -= 5;
					}
					if (patricks[i].rect.x <= -100)
					{
						patricks[i].out = 0;
					}

				}
				patrickcounter++;
				//spawn patricks that shoot in 3 zones
				//get big patrick with button you have to shoot





			}//stage eight

			if (stagenine == 1)
			{
				if (stagenineonce == 1)
				{
					Mix_PlayChannel(-1, mitchend, 0);
					stagenineonce = 0;
				}

				if (mitchjonesy >= 700)
				{
					stagenine = 0;
					stageten = 1;
				}
				if (Mix_Playing(-1) == 0)
				{
					mitchbye = 1;
					mitchjonesy++;
					
				}
				//monologuecounter++;
			}
			if (stageten == 1)
			{
				
				if (stagetenonce == 1)
				{
					ratx = 10;
					stagetenonce = 0;
				}
				if (raty <= 540)
				{
					ratcanttouch = 1;
					if (platformx >= 400)
					{
						platformy--;
						raty--;
						playery--;
					}
					else
					{
						platformx++; 
						ratx++;
					}
					
				}
				else
				{
					ratx++;
					raty--;
				}
				

			}

		}

	}//mitchspawn
	
	void ballmove22()
	{
		if (barneyonce == 1)
		{
			for (int i = 0; i < 5; i++)
			{
				barneylaser[i].texture = ladder;
				barneylaser[i].rect = { -500,-500,75,20 };
				demonlaser[i].texture = ladder;
				demonlaser[i].rect = { -500,-500,75,20 };
			}


			barneyonce = 0;
		}
		if (barneysound5 == 0)
		{
			if (lasercounter % 1000 == 0)
			{
				barneybiglaser = 1;
			}
			if (lasercounter % 55 == 0 && barneybiglaser == 0)
			{
				Mix_PlayChannel(-1, laser, 0);
				barneylaser[currentbarneylaser].rect = { barneyx,barneyy + 50,75,20 };
				barneylaser[currentbarneylaser].out = 1;
				//slope
				barneylaser[currentbarneylaser].angle = (barneyy - playery) / (barneyx - playerx);

				currentbarneylaser++;
				if (currentbarneylaser == 5)
				{
					currentbarneylaser = 0;
				}
			}
			if (lasercounter % 40 == 0)
			{
				if (barneybiglaser == 0)
				{
					Mix_PlayChannel(-1, laser, 0);
				}
				
				demonlaser[currentdemonlaser].out = 1;
				demonlaser[currentdemonlaser].rect = { demonx,demony + 10,75,20 };
				demonlaser[currentdemonlaser].angle = (demony - playery) / (demonx - playerx);

				currentdemonlaser++;
				if (currentdemonlaser == 5)
				{
					currentdemonlaser = 0;
				}
			}

			for (int i = 0; i < 5; i++)
			{
				if (demonlaser[i].out == 1)
				{
					//Mix_PlayChannel(-1, laser, 0);
					SDL_RenderCopyEx(grender, laserr, 0, &demonlaser[i].rect, 150, 0, SDL_FLIP_NONE);
					demonlaser[i].rect.y = (demonlaser[i].angle * demonlaser[i].rect.x) - (demonlaser[i].angle * demonx) + demony;
					demonlaser[i].rect.x -= 10;
				}
				if (barneylaser[i].out == 1)
				{
					//Mix_PlayChannel(-1, laser, 0);
					SDL_RenderCopyEx(grender, laserr, 0, &barneylaser[i].rect, 150, 0, SDL_FLIP_NONE);
				
					barneylaser[i].rect.y = (barneylaser[i].angle * barneylaser[i].rect.x) - (barneylaser[i].angle * barneyx) + barneyy;
					barneylaser[i].rect.x -= 10;
				}



			}
			lasercounter++;
		}


	}


