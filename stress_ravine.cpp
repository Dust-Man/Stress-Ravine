#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <limits>
#include <list>
#include <locale>

#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"
using namespace std ;

bool teclaPresionada=false;


//PROCEDIMIENTOS GENERALES _______________________________________________________________________________________________________________________________________--
void gotoxy(int x, int y) {

	HANDLE hCon;
	hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void OcultarCursor(){
	
	CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Obtenemos la información actual del cursor
    GetConsoleCursorInfo(handle, &cursorInfo);

    // Modificamos la visibilidad del cursor
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &cursorInfo);
}

void MostrarCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Obtenemos la información actual del cursor
    GetConsoleCursorInfo(handle, &cursorInfo);

    // Modificamos la visibilidad del cursor
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(handle, &cursorInfo);
}
//SPACE ODESSEY INICIO_________________________________________________________________________________________________________________________________________________--

void pausa (){
	
	gotoxy(116,2);printf("%c",19);
	
	if(GetAsyncKeyState('P') & 0x8000){
                	gotoxy(116,2);printf("%c",16);
                	getch();
                	gotoxy(116,2); printf("%c",19);
                	
				}
}

void letrero(int x,int y){

    gotoxy(x,y);cout << "     _______..______      ___       ______  _______                         " << endl;
    gotoxy(x,y+1);cout << "    /       ||   _  \\    /   \\     /      ||   ____|                        " << endl;
	gotoxy(x,y+2);cout << "   |   (----`|  |_)  |  /  ^  \\   |  ,----'|  |__                           " << endl;
    gotoxy(x,y+3);cout << "    \\   \\    |   ___/  /  /_\\  \\  |  |     |   __|                          " << endl;
    gotoxy(x,y+4);cout << ".----)   |   |  |     /  _____  \\ |  `----.|  |____                         " << endl;
    gotoxy(x,y+5);cout << "|_______/    | _|    /__/     \\__\\ \\______||_______|                        " << endl;
    gotoxy(x,y+6);cout << "                                                                            " << endl;
    gotoxy(x,y+7);cout << "  ______    _______   _______     _______.     _______. ___________    ____ " << endl;
    gotoxy(x,y+8);cout << " /  __  \\  |       \\ |   ____|   /       |    /       ||   ____\\   \\  /   / " << endl;
    gotoxy(x,y+9);cout << "|  |  |  | |  .--.  ||  |__     |   (----`   |   (----`|  |__   \\   \\/   /  " << endl;
    gotoxy(x,y+10);cout << "|  |  |  | |  |  |  ||   __|     \\   \\        \\   \\    |   __|   \\_    _/   " << endl;
    gotoxy(x,y+11);cout << "|  `--'  | |  '--'  ||  |____.----)   |   .----)   |   |  |____    |  |     " << endl;
    gotoxy(x,y+12); cout << " \\______/  |_______/ |_______|_______/    |_______/    |_______|   |__|     " << endl;
    gotoxy(x,y+13);cout << "                                                                            " << endl;
}

void pintar_limites () {
	for (int i=2; i<118; i++){
		gotoxy(i,3);   printf ("%c",205);               
		gotoxy(i,27); printf ("%c",205);
	}
	
	for (int i=4; i<27; i++) {
		gotoxy(2,i); printf("%c",186);
		gotoxy(117,i); printf("%c",186);
	}
	
	gotoxy(2,3); printf("%c",201); 
	gotoxy(2,27); printf("%c",200); 
	gotoxy(117,3); printf("%c",187); 
	gotoxy(117,27); printf("%c",188); 
}

void animacion_inicio(int x,int x1,int x2,int x3,int y){
		pintar_limites();
	gotoxy(x,y);cout << "      _          " << endl;
    gotoxy(x,y+1);cout << "    /\\ \\         " << endl;
    gotoxy(x,y+2);cout << "   /  \\ \\        " << endl;
    gotoxy(x,y+3);cout << "  / /\\ \\ \\       " << endl;
    gotoxy(x,y+4);cout << " / / /\\ \\ \\      " << endl;
    gotoxy(x,y+5); cout << " \\/_//_\\ \\ \\     " << endl;
    gotoxy(x,y+6);cout << "   __\\___ \\ \\    " << endl;
    gotoxy(x,y+7);cout << "  / /\\   \\ \\ \\   " << endl;
    gotoxy(x,y+8);cout << " / /_/____\\ \\ \\  " << endl;
    gotoxy(x,y+9);cout << "/__________\\ \\ \\ " << endl;
    gotoxy(x,y+10);cout << "\\_____________\\/ " << endl;
    gotoxy(x,y+11);cout << "                  " << endl;
    Sleep(1000);
    system("cls");
    
    	pintar_limites();
    gotoxy(x1,y);cout << "                  " << endl;
    gotoxy(x1,y+1);cout << "    _       " << endl;
    gotoxy(x1,y+2);cout << " /  \\ \\     " << endl;
    gotoxy(x1,y+3);cout << "/ /\\ \\ \\    " << endl;
    gotoxy(x1,y+4);cout << "\\/_/\\ \\ \\   " << endl;
    gotoxy(x1,y+5);cout << "    / / /   " << endl;
   	gotoxy(x1,y+6); cout << "   / / /    " << endl;
    gotoxy(x1,y+7);cout << "  / / /  _  " << endl;
    gotoxy(x1,y+8);cout << " / / /_/\\_\\" << endl;
    gotoxy(x1,y+9);cout << "/ /_____/ / " << endl;
    gotoxy(x1,y+10);cout << "\\________/  " << endl;
    gotoxy(x,y+11);cout << "                  " << endl;
    Sleep(1000);
    system("cls");
    
    	pintar_limites();
    gotoxy(x2,y);cout << "   _              " << endl;
    gotoxy(x2,y+1);cout << "  / /\\            " << endl;
    gotoxy(x2,y+2);cout << " / /  \\           " << endl;
    gotoxy(x2,y+3);cout << "/_/ /\\ \\          " << endl;
    gotoxy(x2,y+4);cout << "\\_\\/\\ \\ \\         " << endl;
    gotoxy(x2,y+5);cout << "     \\ \\ \\        " << endl;
    gotoxy(x2,y+6);cout << "      \\ \\ \\       " << endl;
    gotoxy(x2,y+7);cout << "       \\ \\ \\      " << endl;
   	gotoxy(x2,y+8); cout << "      __\\ \\ \\___  " << endl;
   	gotoxy(x2,y+9); cout << "     /___\\_\\/__/\\ " << endl;
    gotoxy(x2,y+10);cout << "     \\_________\\/ " << endl;
    gotoxy(x2,y+11);cout << "                  " << endl;
    Sleep(1000);
    system("cls");
    
    	pintar_limites();
    gotoxy(x3,y);cout << "         _              _       " << endl;
    gotoxy(x3,y+1);cout << "        /\\ \\           /\\ \\     " << endl;
    gotoxy(x3,y+2);cout << "       /  \\ \\         /  \\ \\    " << endl;
    gotoxy(x3,y+3);cout << "      / /\\ \\_\\       / /\\ \\ \\   " << endl;
    gotoxy(x3,y+4);cout << "     / / /\\/_/      / / /\\ \\ \\  " << endl;
    gotoxy(x3,y+5);cout << "    / / / ______   / / /  \\ \\_\\ " << endl;
    gotoxy(x3,y+6);cout << "   / / / /\\_____\ / / /   / / / " << endl;
    gotoxy(x3,y+7);cout << "  / / /  \\/____ // / /   / / /  " << endl;
    gotoxy(x3,y+8);cout << " / / /_____/ / // / /___/ / /   " << endl;
    gotoxy(x3,y+9);cout << "/ / /______\\/ // / /____\\/    " << endl;
    gotoxy(x3,y+10);cout << "\\/___________/ \\/_________/     " << endl;
    gotoxy(x3,y+11);cout << "                                " << endl;
    Sleep(1000);
    system("cls");
	
		pintar_limites();
	}
	
void pantalla_gameover(int x, int y){
	gotoxy(x, y);
    cout << "  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      " << endl;
    
    y++; // Incrementar la coordenada y
    gotoxy(x, y);
    cout << " /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     " << endl;
    
    y++; // Incrementar la coordenada y
    gotoxy(x, y);
    cout << "|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    " << endl;
    
    y++; // Incrementar la coordenada y
    gotoxy(x, y);
    cout << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     " << endl;
    
    y++; // Incrementar la coordenada y
    gotoxy(x, y);
    cout << "|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--'  |    \\    /    |  |____ |  |\\  \\----." << endl;
    
    y++; // Incrementar la coordenada y
    gotoxy(x, y);
    cout << " \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|" << endl;

}

class NAVE {
	int x, y;
	int corazones;
	int vidas;
public:
	NAVE(int _x, int _y, int _corazones, int _vidas): x(_x), y(_y), corazones(_corazones), vidas (_vidas){}
	int X(){
		return x;
	}
	int Y(){
		return y;
	}
	int V(){
		return vidas;
	}
	
	void COR () {corazones--;}
	void pintar (); 
	void borrar();
	void mover();
	void pintar_corazones();
	void morir (int n);
	void vidas_reinicio (int n) {vidas=n;}
	void corazones_reinicio (int n) {corazones=n;}
	
};

void NAVE::pintar() {
	gotoxy (x,y); printf("  %c",30);
	gotoxy(x, y+1); printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2); printf("%c%c %c%c",30,190,190,30);
}

void NAVE::borrar(){
	gotoxy(x,y);   printf("        ");
	gotoxy(x,y+1); printf("        ");
	gotoxy(x,y+2); printf("        ");
}

void NAVE::mover() {
	if(kbhit()){
	 	char tecla=getch();
	 		borrar();
	 		if (tecla=='j' && x>3) x--;
	 		if (tecla=='l' && x+6 <114 ) x++;
	 		if(tecla=='k' && y+3<27 )y++;
	 		if (tecla=='i' && y>4)y--;
	 		if (tecla=='e')corazones--;
	 		pintar();
	 		pintar_corazones();
	 		
	 }
}

void NAVE::pintar_corazones() {
	gotoxy (50, 2); printf ("VIDAS %d", vidas);
	gotoxy (64,2); printf("SALUD");
	gotoxy (70, 2); printf("               ");
	for (int i=0; i<corazones; i++) {
		gotoxy (70+i, 2); printf ("%c", 3);
		
	}
	
}

void NAVE::morir(int n) {
	if (corazones==0){
		borrar();
		gotoxy(x,y);   printf("   **   ");
		gotoxy(x,y+1); printf("  ****  ");
		gotoxy(x,y+2); printf("   **   ");
		Sleep(200);
		borrar();
		gotoxy(x,y);   printf(" * ** *");
		gotoxy(x,y+1); printf("  **** ");
		gotoxy(x,y+2); printf(" * ** *");
		Sleep(200);
		borrar();
		vidas--;
		corazones =n;
		pintar_corazones();
		pintar();
		
	}
}

class AST{
	int x, y;
public:
	AST(int _x, int _y): x(_x), y(_y) {}
	void pintar();
	void mover();
	void choque(class NAVE &N);
	int X() {return x;}
	int Y() {return y;}
};

void AST::pintar(){
	gotoxy (x,y); printf("%c", 233);	
}

void AST::mover(){
	gotoxy(x,y); printf("  ");
	y++;
	if(y>26){
		x=rand()%108+4;
		y=4;
	}
	pintar();
	
	
}
void AST::choque(class NAVE &N){
	if(x>=N.X() && x<N.X()+6 && y>=N.Y() && y<=N.Y()+2 ){
		N.COR();
		N.borrar();
		N.pintar();
		N.pintar_corazones();
		x=rand()%108+4;
		y=4;
	}
}

class BALA {
	int x, y;
public: 
	BALA(int _x, int _y): x(_x), y(_y){}
	
	int X(){
		return x;
	}
	int Y() {
		return y;
	}
	void mover ();
	bool fuera();
};

void BALA::mover(){
	gotoxy(x,y); printf("   ");
	 y--;
	gotoxy (x,y); printf ("*");
	
	
}

bool BALA::fuera(){
	if(y==4) return true;
	return false;
}

void spaceodessey_main () {
    OcultarCursor();
    int puntos=0;
    int borrar_asteroides=1;
    int nuevoasteroide=0;
    int nV, nC;
    int dism_sleep=0;
    bool gamemode_easy = false;
    bool gamemode_normal = false;
    bool gamemode_hard = false;
    bool gamemode_arcade = false;

    list<AST*> A;
    list<AST*>::iterator itA;

    list<BALA*> B;
    list<BALA*>::iterator it;


    bool execute_game = true;
    while (execute_game) {
    	
    	system("color 06");
    	
        // PANTALLA DE INICIO
        letrero(5, 6);
        pintar_limites();
        SetConsoleOutputCP(65001);
        gotoxy(87, 7);
        cout << "Selecione el modo de juego" << endl;
        gotoxy(87, 8);
        cout << "1. Fácil" << endl;
        gotoxy(87, 9);
        cout << "2. Normal" << endl;
        gotoxy(87, 10);
        cout << "3. Díficil" << endl;
        gotoxy(87, 11);
        cout << "4. Arcade" << endl;
        gotoxy(87,12);
        cout << "5. Regresar a Stress Ravine" << endl;
        int modo;
        gotoxy(87, 14);
        cin >> modo;
        switch (modo) {
            case 1:
                gamemode_easy = true;
                nC = 5;
                nV = 5;
                break;
            case 2: 
            	gamemode_normal = true;
            	nC = 3;
            	nV = 3;
            	break;
            case 3:
            	gamemode_hard = true;
            	nC = 3;
            	nV = 3;
            	break;
            case 4:
                gamemode_arcade = true;
                nC = 3;
                nV = 3;
                break;
            
            case 5:
            	execute_game=false;
            break;
            
        }
        system("cls");

        bool game_over = false;
        NAVE N(56, 24, nC, nV);
        
        SetConsoleOutputCP(437);

        while (gamemode_arcade) { //INICIO GAMEMODE ARCADE	
        	animacion_inicio(48,50,48,40,9);
        	N.pintar();
        	N.pintar_corazones();
        
    	if(borrar_asteroides==1){
    		A.clear();
	          
		}
		
		for (int i = 0; i < 5; i++) {
        	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
    	}
        

        	
        	
            int contador = 0;
            while (!game_over) { //INICIO GAMEOVER ARCADE
                contador++;
                
                pausa();

                gotoxy(2, 2);
                cout << puntos;
                
                
                
                if(nuevoasteroide==15){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==20){
					nuevoasteroide=20;
				}
				
				if(nuevoasteroide==35){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==40){
					nuevoasteroide=40;
				}
				
				if(nuevoasteroide==50){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==55){
					nuevoasteroide=55;
				}
				
				if(nuevoasteroide==65){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==70){
					nuevoasteroide=70;
				}
				
				if(nuevoasteroide==85){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==90){
					nuevoasteroide=90;
				}
				
				if(nuevoasteroide==100){
                	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
                	nuevoasteroide=0;
				}
				
				if(puntos==105){
					nuevoasteroide=105;
				}
				
					


                if (GetAsyncKeyState('A') & 0x8000) {
                    if (!teclaPresionada) {
                        B.push_back(new BALA(N.X() + 2, N.Y() - 1));
                        teclaPresionada = true;
                    }
                } else {
                    teclaPresionada = false;
                }

                for (it = B.begin(); it != B.end(); it++) {
                    (*it)->mover();
                    if ((*it)->fuera()) {
                        gotoxy((*it)->X(), (*it)->Y());
                        printf("   ");
                        delete (*it);
                        it = B.erase(it);
                      
                    }
                }
                
				if(puntos<15){
	                if (contador >= 5) { // Ajusta el valor según la velocidad deseada
	                    for (itA = A.begin(); itA != A.end(); itA++) {
	                        (*itA)->mover();
	                        (*itA)->choque(N);
	                    }
	                    contador = 0;
	                }
	        	}
	        	
	        	else if(puntos<30){
		        	if (contador >= 3) { // Ajusta el valor según la velocidad deseada
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }
		                    contador = 0;
		                }
		        }
		        
		        else if(puntos<45){
		        	if (contador >= 2) { // Ajusta el valor según la velocidad deseada
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }
		                    contador = 0;
		                }
		        }
		        
		        else if(puntos<65){
		        	if (contador >= 1) { // Ajusta el valor según la velocidad deseada
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }
		                    contador = 0;
		                }
		        }
		        
		        else if(puntos<85){
		        	for (itA = A.begin(); itA != A.end(); itA++) {
	                        (*itA)->mover();
	                        (*itA)->choque(N);
	                    }	
		        	
				}
				
				else if(puntos<100){
					for (itA = A.begin(); itA != A.end(); itA++) {
	                        (*itA)->mover();
	                        (*itA)->choque(N);
	                    }
					dism_sleep=5;	
					
				}
				else {
					for (itA = A.begin(); itA != A.end(); itA++) {
	                        (*itA)->mover();
	                        (*itA)->choque(N);
	                    }
					dism_sleep=10;	
					
				}
				
				
		 	

                for (itA = A.begin(); itA != A.end(); itA++) {
                    for (it = B.begin(); it != B.end(); it++) {
                        if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y())) {
                            gotoxy((*it)->X(), (*it)->Y());
                            printf("  ");
                            delete (*it);
                            it = B.erase(it);

                            A.push_back(new AST(rand() % 64, 4));
                            gotoxy((*itA)->X(), (*itA)->Y());
                            printf("  ");
                            delete (*itA);
                            itA = A.erase(itA);

                            puntos += 5;
                            nuevoasteroide+=5;
                        }
                    }
                }
                N.morir(nC);
                N.mover();

                if (N.V() == 0) {
                    game_over = true;
					
					nuevoasteroide=0;
                    N.vidas_reinicio(nV);
                }

                Sleep(30-dism_sleep);
            }
			 //FIN DE GAMEOVER ARCADE
			system("cls");
            pantalla_gameover(10,12);
            gotoxy(10,15); cout<<"SU PUNTAJE FUE DE "<<puntos;
            puntos=0;
            pintar_limites();
            getch();
			gamemode_arcade = false;
			system("cls");
}
            
            
         //FIN DE GAMEMODE ARCADE

        while (gamemode_easy) { //INICIO GAMEMODE EASY
        	animacion_inicio(48,50,48,40,9);
        	N.pintar();
        	N.pintar_corazones();
        	
        if(borrar_asteroides==1){
    		A.clear();
	          
		}
        	
        	for (int i = 0; i < 5; i++) {
        	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
    	}
    		
        	
        	int contador=0;
            while (!game_over) { //INICIO GAMEOVER EASY
            	contador ++;
            	
            	pausa();
            	
                gotoxy(2, 2);
                cout << puntos;

                if (GetAsyncKeyState('A') & 0x8000) {
                    if (!teclaPresionada) {
                        B.push_back(new BALA(N.X() + 2, N.Y() - 1));
                        teclaPresionada = true;
                    }
                } else {
                    teclaPresionada = false;
                }

                for (it = B.begin(); it != B.end(); it++) {
                    (*it)->mover();
                    if ((*it)->fuera()) {
                        gotoxy((*it)->X(), (*it)->Y());
                        printf("   ");
                        delete (*it);
                        it = B.erase(it);
                    }
                }

                if (contador >= 3) { // Ajusta el valor según la velocidad deseada
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }
		                    contador = 0;
		                }

                for (itA = A.begin(); itA != A.end(); itA++) {
                    for (it = B.begin(); it != B.end(); it++) {
                        if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y())) {
                            gotoxy((*it)->X(), (*it)->Y());
                            printf("  ");
                            delete (*it);
                            it = B.erase(it);

                            A.push_back(new AST(rand() % 64, 4));
                            gotoxy((*itA)->X(), (*itA)->Y());
                            printf("  ");
                            delete (*itA);
                            itA = A.erase(itA);

                            puntos += 5;
                        }
                    }
                }
                N.morir(nC);
                N.mover();

                if (N.V() == 0) {
                    game_over = true;
                    
                    N.vidas_reinicio(nV);
                }

                Sleep(30-dism_sleep);
            } //FIN GAMEOVER EASY
            system("cls");
            pantalla_gameover(10,12);
            gotoxy(10,15); cout<<"SU PUNTAJE FUE DE "<<puntos;
            puntos=0;
            pintar_limites();
            getch();
			gamemode_easy = false;
			system("cls");
        }// FIN GAMEMODE EASY
        
        while (gamemode_normal) { //INICIO GAMEMODE NORMAL
        	
        	animacion_inicio(48,50,48,40,9);
        	N.pintar();
        	N.pintar_corazones();
        	
        	if(borrar_asteroides==1){
    		A.clear();
	          
		}
        	for (int i = 0; i < 5; i++) {
        	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
    	}
        	
        	int contador=0;
            while (!game_over) { //INICIO GAME OVER NORMAL
            	contador ++;
            	
            	pausa();
            	
                gotoxy(2, 2);
                cout << puntos;

                if (GetAsyncKeyState('A') & 0x8000) {
                    if (!teclaPresionada) {
                        B.push_back(new BALA(N.X() + 2, N.Y() - 1));
                        teclaPresionada = true;
                    }
                } else {
                    teclaPresionada = false;
                }

                for (it = B.begin(); it != B.end(); it++) {
                    (*it)->mover();
                    if ((*it)->fuera()) {
                        gotoxy((*it)->X(), (*it)->Y());
                        printf("   ");
                        delete (*it);
                        it = B.erase(it);
                    }
                }
				if(puntos<35){
	                if (contador >= 2) { // Ajusta el valor según la velocidad deseada
			                    for (itA = A.begin(); itA != A.end(); itA++) {
			                        (*itA)->mover();
			                        (*itA)->choque(N);
			                    }
			                    contador = 0;
			                }
				}
		        
		        else {
		        	if (contador >= 1) { // Ajusta el valor según la velocidad deseada
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }
		                    contador = 0;
		                }
		        }

                for (itA = A.begin(); itA != A.end(); itA++) {
                    for (it = B.begin(); it != B.end(); it++) {
                        if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y())) {
                            gotoxy((*it)->X(), (*it)->Y());
                            printf("  ");
                            delete (*it);
                            it = B.erase(it);

                            A.push_back(new AST(rand() % 64, 4));
                            gotoxy((*itA)->X(), (*itA)->Y());
                            printf("  ");
                            delete (*itA);
                            itA = A.erase(itA);

                            puntos += 5;
                        }
                    }
                }
                N.morir(nC);
                N.mover();

                if (N.V() == 0) {
                    game_over = true;
                    
                    N.vidas_reinicio(nV);
                }

                Sleep(30-dism_sleep);
            } //FIN GAMEOVER NORMAL
            system("cls");
            system("cls");
            pantalla_gameover(10,12);
            gotoxy(10,15); cout<<"SU PUNTAJE FUE DE "<<puntos;
            puntos=0;
            pintar_limites();
            getch();
			gamemode_normal = false;
			system("cls");
        } //FIN GAMEMODE NORMAL
        
        while (gamemode_hard) { //INICIO GAMEMODE HARD
                	animacion_inicio(48,50,48,40,9);
        			N.pintar();
        			N.pintar_corazones();
        				if(borrar_asteroides==1){
    					A.clear();
						}
				        for (int i = 0; i < 7; i++) {
				        	A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
				    	}
        	int contador=0;
            while (!game_over) {
            	contador ++;
            	
            	pausa();
            	
                gotoxy(2, 2);
                cout << puntos;

                if (GetAsyncKeyState('A') & 0x8000) {
                    if (!teclaPresionada) {
                        B.push_back(new BALA(N.X() + 2, N.Y() - 1));
                        teclaPresionada = true;
                    }
                } else {
                    teclaPresionada = false;
                }

                for (it = B.begin(); it != B.end(); it++) {
                    (*it)->mover();
                    if ((*it)->fuera()) {
                        gotoxy((*it)->X(), (*it)->Y());
                        printf("   ");
                        delete (*it);
                        it = B.erase(it);
                    }
                }
				
		                    for (itA = A.begin(); itA != A.end(); itA++) {
		                        (*itA)->mover();
		                        (*itA)->choque(N);
		                    }

                for (itA = A.begin(); itA != A.end(); itA++) {
                    for (it = B.begin(); it != B.end(); it++) {
                        if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y())) {
                            gotoxy((*it)->X(), (*it)->Y());
                            printf("  ");
                            delete (*it);
                            it = B.erase(it);

                            A.push_back(new AST(rand() % 64, 4));
                            gotoxy((*itA)->X(), (*itA)->Y());
                            printf("  ");
                            delete (*itA);
                            itA = A.erase(itA);

                            puntos += 5;
                        }
                    }
                }
                N.morir(nC);
                N.mover();

                if (N.V() == 0) {
                    game_over = true;
                    N.vidas_reinicio(nV);
                }

                Sleep(30-dism_sleep);
            } //FIN GAMEOVER HARD 
            system("cls");
            pantalla_gameover(10,12);
            gotoxy(10,15); cout<<"SU PUNTAJE FUE DE "<<puntos;
            puntos=0;
            pintar_limites();
            getch();
			gamemode_hard = false;
			system("cls");
            system("cls");
        }// FIN GAMEMODE HARD 
        
    }
}

//SPACE ODESSEY FIN____________________________________________________________________________________________________________________________________________________--


//TRIVIA INICIO:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::..
void colores();
void menu();
void deportes();
void historia();
void quimica();
void acertijos();
void matematica();
void configuracion();
void sports();
void history();
void chemistry();
void riddles();
void math();
void menui();
void configurationi();    






	//Declaracion las distintas secciones a traves de funciones 
//Deportes ´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´
void deportes(){
	bool repite=true;
do{

	system("cls");
    			string r[20];
    			int a=0;
    		gotoxy(45,1);	cout<<"-----Trivia deportiva-----"<<endl;

    srand(time(0));

     string preguntas[20] = {
"¿En qué deporte se utiliza una maza y una pelota pequeña?",
"¿Cuál es el único deporte en el que se usa un arco y una flecha?",
"¿Qué jugador de baloncesto es conocido como Air Jordan?",
"¿En qué país se originó el deporte del rugby?",
"¿Cuál es el récord mundial en los 100 metros lisos en atletismo?",
"¿Cuál es el país con más títulos mundiales en fútbol?",
"¿En qué deporte se utiliza un palo llamado crosse?",
"¿Cuál es el deporte más popular en la India?",
"¿Qué equipo de béisbol tiene el récord de más victorias en una sola temporada de las Grandes Ligas?",
"¿Cuál es el tenista con más títulos de Grand Slam en la historia?",
"¿Cuál es el nombre del estadio de fútbol del FC Barcelona?",
"¿Cuántos jugadores hay en un equipo de voleibol?",
"¿En qué deporte se utiliza una tabla para deslizarse sobre las olas?",
"¿Cuál es el boxeador con más títulos mundiales en diferentes categorías de peso?",
"¿Cuál es el deporte nacional de Canadá?",
"¿En qué ciudad se encuentra el circuito de carreras de Fórmula 1 conocido como Monza ?",
"¿Cuál es el deporte olímpico más antiguo?",
"¿Qué país ha ganado más medallas de oro en los Juegos Olímpicos de Verano?",
"¿Cuál es el equipo de fútbol con más Champions League ganadas?",
"¿Cuál es el deporte en el que se premia con una  jersey amarilla al líder de la clasificación general?" 
        
    };

    
    random_shuffle(begin(preguntas), end(preguntas));


    for (int i = 0; i < 10; i++){
        cout <<"\n"<<i+1<<"."<< preguntas[i] << endl;
        //Inicio de las opciones de las preguntas
        if(preguntas[i]=="¿En qué deporte se utiliza una maza y una pelota pequeña?"){
        	cout<<"a)Golf b)Polo c)Croquet d)Cricket";
        	cout<<"\nResponde:";cin>>r[i];
        	if(r[i]=="B" || r[i]== "b"){
        		cout<<"\nRespuesta correcta";
        		a++;
			}
			else{
				cout<<"Respuesta incorrecta"<<endl;
			}
		}
		else if(preguntas[i]=="¿Cuál es el único deporte en el que se usa un arco y una flecha?"){
			cout<<"a) Tiro con arco b) Béisbol c) Esgrima d) Surf"<<endl;
			cout<<"Responde:";cin>>r[i];
			if(r[i]=="A" || r[i]=="a"){
				cout<<"\nRespuesta correcta";
				a++;
			}
			else{
				cout<<"\nRespuesta incorrecta";
			}
		}
   else if(preguntas[i]=="¿Qué jugador de baloncesto es conocido como Air Jordan?"){
   	cout<<"a)Michael Jordan b)LeBron James c)Kobe Bryant  d)Magic Johnson"<<endl;
   	cout<<"Responde:";cin>>r[i];   	
   if(r[i]=="a" || r[i]=="A"){
   	cout<<"\nRespuesta correcta ";
   	a++;}
   	else{
   		cout<<"\nRespuesta  incorrecta";
	   }
   }
   
   else if (preguntas[i]=="¿En qué país se originó el deporte del rugby?"){
   	cout<<"a) Inglaterra  b) Nueva Zelanda c) Australia d) Sudáfrica"<<endl;
   	cout<<"Respuesta:";cin>>r[i];
   	if(r[i]=="a" || r[i]=="A"){
   		cout<<"\nRespusta correcta";
   		a++;	   }
   		else{
   			cout<<"\nRespuesta incorrecta";
		   }
   }
   
   else if(preguntas[i]=="¿Cuál es el récord mundial en los 100 metros lisos en atletismo?"){
    cout<<"a) 9,58 segundos b) 9,63 segundos c) 9,69 segundos d) 9,74 segundos";
    cout<<"\nResponde:";cin>>r[i];
    if(r[i]=="a" || r[i]=="A"){
    	cout<<"\nRespuesta correcta";
    	a++;
	}
	else{
		cout<<"\nRespuesta incorrectaa ";
		
	}
   }
   
   else if(preguntas[i]=="¿Cuál es el país con más títulos mundiales en fútbol?"){
   	
cout<<"a) Brasil b) Alemania c) Italia d) Argentina"<<endl;
cout<<"Responde:"<<endl;cin>>r[i];
if(r[i]=="a" || r[i]=="A"){
	cout<<"Respuesta correcta"<<endl;
	a++;
}
else{
	cout<<"Respuesta incorrecta"<<endl;
}
   }
   else if(preguntas[i]=="¿En qué deporte se utiliza un palo llamado crosse?"){
   	cout<<"a) Lacrosse b) Golf c) Hockey sobre hielo d) Polo acuático"<<endl;
   	cout<<"Responde:"<<endl;cin>>r[i];
   	if(r[i]=="a" || r[i]=="A"){
   		cout<<"Respuesta correcta"<<endl;
		   a++;	   }
		   else{
		   	cout<<"Respuesta incorrecta";
		   }
   }
   else if(preguntas[i]=="¿Cuál es el deporte más popular en la India?"){
   	cout<<"a) Cricket b) Fútbol c) Bádminton d) Tenis"<<endl;
   	cout<<"Responde:"<<endl;cin>>r[i];
   	if(r[i]=="a" || r[i]=="A"){
   		cout<<"Respuesta correcta"<<endl;
   		a++;
	   }
	   else{
	   	cout<<"Respuesta incorrecta"<<endl;
	   }
   }
   else if(preguntas[i]=="¿Qué equipo de béisbol tiene el récord de más victorias en una sola temporada de las Grandes Ligas?"){
   	cout<<"a) New York Yankees b) Chicago Cubs c) Boston Red Sox d) Los Angeles Dodgers"<<endl;
   	cout<<"Responde:"<<endl;cin>>r[i];
   	if(r[i]=="a" || r[i]=="A"){
   		cout<<"Respuesta correcta"<<endl;
   		a++;
	   }
	   else{
	   	cout<<"Respuesta incorrecta"<<endl;
}
}

   else if(preguntas[i]=="¿Cuál es el tenista con más títulos de Grand Slam en la historia?"){
   	cout<<"a) Roger Federer b) Rafael Nadal c) Novak Djokovic d) Pete Sampras"<<endl;
   	cout<<"Responde:"<<endl;cin>>r[i];
   	if(r[i]=="a"|| r[i]=="A"){
   		cout<<"Respuesta correcta"<<endl;
   		a++;   		
	   }
	   else{
	   	cout<<"Respuesta incorrecta"<<endl;
	   }
   }
   
   else if(preguntas[i]=="¿Cuál es el nombre del estadio de fútbol del FC Barcelona?"){
   	cout<<"a) Camp Nou b) Santiago Bernabéu c) Old Trafford d) Anfield"<<endl;
   	cout<<"Responde"<<endl;cin>>r[i];
   	if(r[i]=="a"|| r[i]=="A"){
   		cout<<"Respuesta correcta"<<endl;
   		a++;
	   }
	   else{
	   	cout<<"Respuesta incorrecta"<<endl;
	   }
   }

else if(preguntas[i]=="¿Cuántos jugadores hay en un equipo de voleibol?"){
	cout<<"a) 6 b) 7 c) 5 d) 8"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
		
	}
}

else if(preguntas[i]=="¿En qué deporte se utiliza una tabla para deslizarse sobre las olas?"){
	cout<<"a) Surf b) Esquí acuático c) Windsurf d) Paddleboarding"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(preguntas[i]=="¿Cuál es el boxeador con más títulos mundiales en diferentes categorías de peso?"){
	cout<<"a) Manny Pacquiao b) Floyd Mayweather Jr. c) Muhammad Ali d) Sugar Ray Leonard"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl,
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if (preguntas[i]=="¿Cuál es el deporte nacional de Canadá?"){
	cout<<"a) Hockey sobre hielo b) Fútbol c) Lacrosse d) Béisbol"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
	a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(preguntas[i]=="¿En qué ciudad se encuentra el circuito de carreras de Fórmula 1 conocido como Monza ?"){
	cout<<"a) Milán, Italia b) Barcelona, España c) Mónaco d) Londres, Reino Unido"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl,
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(preguntas[i]=="¿Cuál es el deporte olímpico más antiguo?"){
	cout<<"a) Atletismo b) Lucha c) Tiro con arco d) Natación"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a"|| r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;	}
		else{
			cout<<"Respuesta incorrecta"<<endl;
		}
}

else if(preguntas[i]=="¿Qué país ha ganado más medallas de oro en los Juegos Olímpicos de Verano?"){
	cout<<"a) Estados Unidos b) China c) Rusia d) Alemania"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
	
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if (preguntas[i]=="¿Cuál es el equipo de fútbol con más Champions League ganadas?"){
	cout<<"a) Real Madrid b) Barcelona c) Bayern Munich d) Liverpool"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(preguntas[i]=="¿Cuál es el deporte en el que se premia con una  jersey amarilla al líder de la clasificación general?"){
	cout<<"a) Ciclismo (Tour de Francia) b) Tenis  c) Baloncesto d) Golf"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
} //For  deportes 
//Puntaje :Deportes 
cout<<"\nPuntucion final :"<<a<<endl;
if(a>=1 && a<=5){
	cout<<"Ve mas deporte"<<endl;
}
else if(a>=6 && a<=8){
	cout<<"Bien ahí";
}
else if(a==0){
	cout<<"Se te va a aparecer el paletas en la noche .";
}
else{
	cout<<"Ya ponte a chambear"<<endl;
}
//Extra
string o;
cout<<"\n-------------------------------------------";
cout<<"\n1.Regresar al menu principal.";
cout<<"\n2.Salir.";
cout<<"\nQue quieres hacer:";cin>>o;
if(o=="1"){
	repite=false;
	break;
}
else if(o=="2"){
		exit(0);
}
	

else if(o!="1" && o!="2"){
	cout<<"\nVuelve a intentarlo";
	
}
getch();
}while(repite);

}
//Fin deportes ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//Historia ****************************************************************
void historia(){
	bool repite=true;
	do{
	string r[20];
int a=0;
	system("cls");
	  srand(time(0));

    string ph[20] = {
    		"¿En qué año se firmó la Declaración de Independencia de los Estados Unidos?",
"¿Cuál fue el emperador romano conocido como  El Grande?",
"¿En qué año comenzó la Revolución Francesa?",
"¿Cuál fue la capital del Imperio Inca?",
"¿Quién fue el líder de la Revolución Rusa en 1917?",
"¿En qué año terminó la Segunda Guerra Mundial?",
"¿Qué evento histórico marcó el fin de la Guerra Fría?",
"¿Quién fue el líder de la Revolución Cubana en 1959?",
"¿Cuál fue la antigua capital de Japón antes de Tokio?",
"¿En qué año se descubrió América por parte de Cristóbal Colón?",
"¿Cuál fue la batalla que marcó el final de Napoleón Bonaparte?",
"¿En qué año se fundó la Organización de las Naciones Unidas (ONU)?",
"¿Quién fue el líder de la Revolución Mexicana en 1910?",
"¿Cuál fue la primera civilización en Mesopotamia?",
"¿En qué año se fundó la ciudad de Roma?",
"¿Quién fue el primer presidente de Estados Unidos?",
"¿Cuál fue la civilización que construyó las pirámides de Teotihuacán en México?",
"¿En qué siglo se llevó a cabo la Revolución Industrial?",
"¿Cuál fue la capital del Imperio Romano de Oriente?",
"¿Quién fue el líder político  de la India en la lucha por la independencia contra el dominio británico?"
    	 	
        
    };


 
	gotoxy(45,1);cout<<"-----Trivia de Historia-----";
	
	
	 random_shuffle(begin(ph), end(ph));
	
	for (int i = 0; i < 10; i++) {
        cout <<"\n"<<i+1<<"."<< ph[i] << endl;
	//incio de las opciones de las preguntas
	
	if(ph[i]=="¿En qué año se firmó la Declaración de Independencia de los Estados Unidos?"){
		cout<<"a) 1776 b) 1789 c) 1804  d) 1812"<<endl;
		cout<<"Responde:"<<endl;cin>>r[i];
		if(r[i]=="A" || r[i]=="a"){
			cout<<"Respuesta correcta"<<endl;
			a++;
		}
	 else{
	 	cout<<"Respuesta incorrecta"<<endl;	 }
	}
	
else if(ph[i]=="¿Cuál fue el emperador romano conocido como  El Grande?"){
	cout<<"a) Augusto  b) Nerón c) Trajano d) Constantino"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else {
		cout<<"Respuesta incorrecta"<<endl;
	}
}

	else if(ph[i]=="¿En qué año comenzó la Revolución Francesa?"){
		cout<<"a) 1789 b) 1804 c) 1812 d) 1830"<<endl;
		cout<<"Responde:"<<endl;cin>>r[i];
			if(r[i]=="a" || r[i]=="A"){
				cout<<"Respuesta correcta "<<endl,
				a++;
			}
			else{
				cout<<"Respusta incorrecta"<<endl;
			}
		}

else if(ph[i]=="¿Cuál fue la capital del Imperio Inca?"){
	cout<<"a) Cuzco b) Tenochtitlán c) Machu Picchu d) Quito"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta "<<endl;
	}
}

else if(ph[i]=="¿Quién fue el líder de la Revolución Rusa en 1917?"){
	cout<<"a) Vladimir Lenin b) Joseph Stalin c) Leon Trotsky d) Nikita Khrushchev"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿En qué año terminó la Segunda Guerra Mundial?"){
	cout<<"a) 1945 b) 1939 c) 1942 d) 1950"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{ 
	cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿Qué evento histórico marcó el fin de la Guerra Fría?"){
	cout<<"a) Caída del Muro de Berlín b) Revolución Cubana c) Crisis de los Misiles en Cuba d) Guerra de Corea"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="A" || r[i]=="a"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta inocrrecta"<<endl;
	}
}

else if(ph[i]=="¿Quién fue el líder de la Revolución Cubana en 1959?"){
	cout<<"a) Fidel Castro b) Che Guevara c) Fulgencio Batista d) Raúl Castro"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="A" || r[i]=="a"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta	"<<endl;
}
}

else if(ph[i]=="¿Cuál fue la antigua capital de Japón antes de Tokio?"){
	cout<<"a) Kioto b) Osaka c) Nagoya d) Hiroshima"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a"|| r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;}
}

else if(ph[i]=="¿En qué año se descubrió América por parte de Cristóbal Colón?"){
	cout<<"a) 1492 b) 1500 c) 1521 d) 1550"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="A" || r[i]=="a"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
	
	
	
	
}

else if(ph[i]=="¿Cuál fue la batalla que marcó el final de Napoleón Bonaparte?"){
	cout<<"a) Batalla de Waterloo b) Batalla de Austerlitz c) Batalla de Trafalgar d) Batalla de Borodino"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
	a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿En qué año se fundó la Organización de las Naciones Unidas (ONU)?"){
	cout<<"a) 1945 b) 1919 c) 1955 d) 1939"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a"  || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
		}
		else{
			cout<<"Respuesta incorrecata"<<endl;
					}
}

else if (ph[i]=="¿Quién fue el líder de la Revolución Mexicana en 1910?"){
	cout<<"a) Francisco Villa b) Emiliano Zapata c) Porfirio Díaz d) Venustiano Carranza"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
   if(r[i]=="b"|| r[i]=="B"){
   	cout<<"Respuesta correcta"<<endl;
   	a++;
   }
   else{
   	cout<<"Respuesta incorrecta"<<endl;
   }
}

else if(ph[i]=="¿Cuál fue la primera civilización en Mesopotamia?"){
	cout<<"a) Sumerios b) Persas c) Egipcios d) Babilonios"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a"||r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿En qué año se fundó la ciudad de Roma?"){
	cout<<"a) 753 a.C. b) 476 d.C. c) 27 a.C. d) 69 d.C."<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿Quién fue el primer presidente de Estados Unidos?"){
	cout<<"a) George Washington b) Thomas Jefferson c) Abraham Lincoln d) Benjamin Franklin"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
		
	}
}

else if(ph[i]=="¿Cuál fue la civilización que construyó las pirámides de Teotihuacán en México?"){
	cout<<"a) Mayas b) Aztecas c) Olmecas d) Toltecas"<<endl;
	cout<<"Responde"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		cout<<"Responde:"<<endl;cin>>r[i];
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ph[i]=="¿En qué siglo se llevó a cabo la Revolución Industrial?"){
	cout<<"a) Siglo XVIII b) Siglo XIX c) Siglo XVII d) Siglo XX"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta icorrecta"<<endl;
		
	}
}

else if(ph[i]=="¿Cuál fue la capital del Imperio Romano de Oriente?"){
	cout<<"a) Constantinopla b) Roma c) Atenas d) Alejandría"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesa incorrecta"<<endl;
	}
}

else if(ph[i]=="¿Quién fue el líder político  de la India en la lucha por la independencia contra el dominio británico?"){
	cout<<"a) Mahatma Gandhi b) Jawaharlal Nehru c) Indira Gandhi d) Rajendra Prasad"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	
	else {
	
		cout<<"Respuesta incorrecta"<<endl;
	}
}
}//For historia 

//Puntaje:Historia 
cout<<"Tu puntuacion final fue:"<<a;
	if(a>=1 && a<=5){
	cout<<"Lee mas libros"<<endl;
}
else if(a>=6 && a<=8){
	cout<<"Bien ahí";
}
else if(a==0){
	cout<<"Se te va a aparecer el paletas en la noche .";
}
else{
	cout<<"Felicidades"<<endl;
}
//Extra
string o;
cout<<"\n-------------------------------------------";
cout<<"\n1.Regresar al menu principal.";
cout<<"\n2.Salir.";
cout<<"\nQue quieres hacer:";cin>>o;
if(o=="1"){
	repite=false;
}
else if(o=="2"){
		exit(0);
}
	

else if(o!="1" && o!="2"){
	cout<<"\nVuelve a intentarlo";
	
}

getch();
}while(repite);
}
//Fin Historia *****************************************************

//Quimica ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void quimica(){
	bool repite=true;
	do{
	
	system("cls");
	  srand(time(0));
string r[20];
    string pq[20] = {
"¿Cuál es el elemento químico más abundante en la corteza terrestre?",
"¿Cuál es la fórmula química del agua?",
"¿Cuál es el número atómico del carbono?",
"¿Cuál es el gas noble más ligero?",
"¿Cuál es el proceso químico mediante el cual las plantas convierten la luz solar en energía?",
"¿Cuál es el compuesto químico responsable del olor característico de la lluvia?",
"¿Cuál es el metal más ligero y menos denso?",
"¿Cuál es el proceso químico que implica la pérdida de electrones?",
"¿Cuál es el elemento químico utilizado como conductor en la fabricación de cables eléctricos?",
"¿Cuál es el ácido presente en las células del estómago humano?",
"¿Cuál es el proceso químico que libera energía al romperse un enlace químico?",
"¿Cuál es el elemento químico más pesado de la tabla periódica?",
"¿Cuál es el pH neutro?",
"¿Cuál es el compuesto químico responsable del olor característico de los plátanos maduros?",
"¿Cuál es el proceso químico que convierte un sólido directamente en gas sin pasar por el estado líquido?",
"¿Cuál es el compuesto químico responsable del color verde en las plantas?",
"¿Cuál es el gas que las plantas liberan durante la fotosíntesis?",
"¿Cuál es el compuesto químico presente en los huesos y dientes que ayuda a fortalecerlos?",
"¿Cuál es el proceso químico que convierte azúcares en alcohol y dióxido de carbono?",
"¿Cuál es el elemento químico esencial en la estructura de los huesos y los dientes?"
    	 	
        
    };

    int a=0;
 
	gotoxy(45,1);cout<<"-----Trivia de Quimica-----";
	
	
	 random_shuffle(begin(pq), end(pq));
	 for (int i = 0; i < 10; i++) {
        cout <<"\n"<<i+1<<"."<< pq[i] << endl;
	//incio de las opciones de las preguntas
	 if(pq[i]=="¿Cuál es el elemento químico más abundante en la corteza terrestre?"){
	 	cout<<"a) Hierro ) Silicio c) Oxígeno d) Aluminio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i]; 
		 if(r[i]=="c" || r[i]=="C"){
		 cout<<"Respuesta correcta "<<endl;
		 a++;	
		 }	
		 else{
		 	cout<<"Respuesta incoorrecta"<<endl;
		 }
	}
	 
	 else if(pq[i]=="¿Cuál es la fórmula química del agua?"){
	 	cout<<"a) CO2 b) NaCl c) H2O d) CH4"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="c" || r[i]=="C"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el número atómico del carbono?"){
	 cout<<"a) 12 b) 16 c) 6 d) 20"<<endl;
	 cout<<"Responde:"<<endl;cin>>r[i];
	 if(r[i]=="c" || r[i]=="C"){
	 	cout<<"Respuesta correcta"<<endl;
	 	a++;
	 }
	 else{
	 	cout<<"Respuesta incorrecta"<<endl;
	 }
	 
	 }
	 
	 else if(pq[i]=="¿Cuál es el gas noble más ligero?"){
	 	cout<<"a) Neón b) Argón c) Xenón d) Helio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="d" || r[i]=="D"){
	 		cout<<"Respuesta correcta "<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 	
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el proceso químico mediante el cual las plantas convierten la luz solar en energía?"){
	 	cout<<"a) Respiración b) Fermentación c) Fotosíntesis d) Combustión"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="c" || r[i]=="C"){
	 		cout<<"Resuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
		 }	 
	 
	 else if(pq[i]=="¿Cuál es el compuesto químico responsable del olor característico de la lluvia?"){
	 	cout<<"a) Amoníaco b) Metano c) Ozono d) Geosmina"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="d" || r[i]=="D"){
	 		cout<<"Respueata correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el metal más ligero y menos denso?"){
	 	cout<<"a) Aluminio b) Titanio c) Litio d) Magnesio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	
	 	if(r[i]=="c" || r[i]=="C"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
		 
	}		 
		 
	else if(pq[i]=="¿Cuál es el proceso químico que implica la pérdida de electrones?"){
		cout<<"a) Reducción b) Hidrólisis c) Combustión d) Oxidación"<<endl;
		cout<<"Responde:"<<endl;cin>>r[i];
		if(r[i]=="d" || r[i]=="D"){
		cout<<"Respuesta correcta"<<endl;
		a++;
		}
		else{
			cout<<"Respuesta incorrecta"<<endl;
		}
	}
	
		else if(pq[i]=="¿Cuál es el elemento químico utilizado como conductor en la fabricación de cables eléctricos?"){
			cout<<"a) Plomo b) Cobre c) Hierro d) Zinc"<<endl;
			cout<<"Responde:"<<endl;cin>>r[i];
			if(r[i]=="b" || r[i]=="B"){
				cout<<"Respuesta correcta"<<endl;
			a++;}
		else{
			cout<<"Respuesta incorrecta"<<endl;
		}		
			} 
	 
	else if(pq[i]=="¿Cuál es el ácido presente en las células del estómago humano?") {
		cout<<"a) Ácido acético b) Ácido cítrico c) Ácido clorhídrico d) Ácido sulfúrico"<<endl;
		cout<<"Responde:"<<endl;cin>>r[i];
		if(r[i]=="c" || r[i]=="C"){
			cout<<"Respuesta correcta"<<endl;
			a++;
		}	
		else{
			cout<<"Respuesta incorrecta";
		}
	}
	 
	 else if(pq[i]=="¿Cuál es el proceso químico que libera energía al romperse un enlace químico?"){
	 	cout<<"a) Endotérmico b) Hidrofóbico c) Exotérmico d) Electroquímico"<<endl;
	 	cout<<"Rewsponde:"<<endl;cin>>r[i];
	 		if(r[i]=="c" || r[i]=="C"){
	 			cout<<"Respuesta correcta"<<endl;
	 			a++;
			 }
			 else{
			 	cout<<"Respuesta incorrecta"<<endl;
			 }
		}
	 
	 else if(pq[i]=="¿Cuál es el elemento químico más pesado de la tabla periódica?"){
	 	cout<<"a) Uranio b) Osmio c) Oro d) Plutonio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="d"||r[i]=="D"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el pH neutro?"){
	 	cout<<"a) 5 b) 1 c) 7 d) 10"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="c" || r[i]=="C"){
	 		
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }	 
		 else{
		 	cout<<"Repuesta incorrecta"<<endl;
		 	
		 }
	}
	 
	 else if(pq[i]=="¿Cuál es el compuesto químico responsable del olor característico de los plátanos maduros?"){
	 	cout<<"a) Ácido acético b) Acetona c) Acetileno d) Etileno"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];	
		 if(r[i]=="d" || r[i]=="D"){
		 	cout<<"Respuesta correcta"<<endl;
		 	a++;
		 }
		 else{
		 	cout<<"Resspuesta incorrecta"<<endl;
		 } 
	}
	 
	 else if (pq[i]=="¿Cuál es el proceso químico que convierte un sólido directamente en gas sin pasar por el estado líquido?"){
	 	cout<<"a) Evaporación b) Sublimación c) Condensación d) Solidificación"<<endl;
	 	cout<<"Responde"<<endl;cin>>r[i];
		 if(r[i]=="b" || r[i]=="B"){
		 	cout<<"Respuesta correcta"<<endl;
		 	a++;
		 }	 
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
		 }
	 
	 else if(pq[i]=="¿Cuál es el elemento químico esencial en la estructura de los huesos y los dientes?"){
	 	cout<<"a) Potasiob) Calcio c) Sodio d) Magnesio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="b" || r[i]=="B"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el compuesto químico responsable del color verde en las plantas?"){
	 	cout<<"a) Hemoglobina b) Clorofila c) Melanina d) Caroteno"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="b" || r[i]=="B"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el gas que las plantas liberan durante la fotosíntesis?"){
	 	cout<<"a) Dióxido de carbono b) Metano c) Oxígeno d) Monóxido de carbono"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="c" || r[i]=="C"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta  incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el compuesto químico presente en los huesos y dientes que ayuda a fortalecerlos?"	){
	 	cout<<"a) Sulfato de calcio b) Carbonato de calcio c) Fluoruro de calcio d) Fosfato de calcio"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="d"|| r[i]=="D"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		 }
	 }
	 
	 else if(pq[i]=="¿Cuál es el proceso químico que convierte azúcares en alcohol y dióxido de carbono?"){
	 	cout<<"a) Combustión b) Fermentación c) Destilación d) Oxidación"<<endl;
	 	cout<<"Responde:"<<endl;cin>>r[i];
	 	if(r[i]=="b"|| r[i]=="B"){
	 		cout<<"Respuesta correcta"<<endl;
	 		a++;
		 }
		 else{
		 	cout<<"Respuesta incorrecta"<<endl;
		
		 }
	 }	 
	 
}//For
	 
	 
	 //Puntuacion:Quimica
	cout<<"\nPuntucion final :"<<a<<endl;
if(a>=1 && a<=5){
	cout<<"Pon atencion a las clases "<<endl;
}
else if(a>=6 && a<=8){
	cout<<"Bien ahí";
}
else if(a==0){
	cout<<"Se te va a aparecer el paletas en la noche .";
}
else{
	cout<<"Felicidades"<<endl;
}
//Extra
string o;
cout<<"\n-------------------------------------------";
cout<<"\n1.Regresar al menu principal.";
cout<<"\n2.Salir.";
cout<<"\nQue quieres hacer:";cin>>o;
if(o=="1"){
	repite=false;
}
else if(o=="2"){
		exit(0);
}
	

else if(o!="1" && o!="2"){
	cout<<"\nVuelve a intentarlo";
	
}

getch();
}while(repite);
		 }	
	//Fin quimica +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 
		 

//Acertijos #############################################################################################
void acertijos(){
	bool repite=true;
	do{
		system("cls");
    			int a=0;
    			string r[20];
    		gotoxy(45,1);	cout<<"-----Acertijos-----"<<endl;

    srand(time(0));

    string ac[20] = {
    "Soy redonda como una pelota, vuelo en el cielo y tengo rayos en el pelo. ¿Quién soy?",
    "Puedo correr sin tener piernas, pero siempre me detengo al llegar a la meta. ¿Qué soy?",
    "Si me nombras, desaparezco. ¿Qué soy?",
    "Me puedes partir en pedazos, pero siempre estaré completo. ¿Qué soy?",
    "Si me necesitas, me desechas. Si no me necesitas, me guardas. ¿Qué soy?",
    "Tengo ciudades pero no calles, bosques pero no árboles, y ríos pero no agua. ¿Qué soy?",
    "Tengo llaves pero no puertas, tengo espacio pero no habitaciones. ¿Qué soy?",
    "Cuanto más me quitas, más grande me vuelvo. ¿Qué soy?",
    "Tengo ojos pero no veo, tengo piernas pero no camino. ¿Qué soy?",
    "Tengo ciudades pero no países, ríos pero no agua, y montañas pero no tierra. ¿Qué soy?",
    "Siempre estoy delante del pasado, pero detrás del futuro. ¿Qué soy?",
    "No hablo, no tengo garganta, pero todos me entienden. ¿Qué soy?",
    "Subo cuando el agua baja, pero me ahogo cuando sube. ¿Qué soy?",
    "Siempre estoy en el aire, pero nunca me ves. ¿Qué soy?",
    "Todos me quieren, todos me buscan, pero cuando me encuentran, me desechan. ¿Qué soy?",
    "Soy un número de dos cifras. Si me sumas con mi inverso, el resultado siempre es 11. ¿Qué número soy?",
    "Tengo ojos pero no veo, tengo agua pero no me mojo. ¿Qué soy?",
    "Siempre corro pero nunca camino, tengo boca pero no hablo. ¿Qué soy?",
    "Soy alto cuando soy joven, pero bajo cuando soy viejo. ¿Qué soy?",
    "Tengo manos pero no puedo aplaudir, tengo un rostro pero no puedo sonreír. ¿Qué soy?"	
        
    };

    random_shuffle(begin(ac), end(ac));

    for (int i = 0; i < 10; i++ ) {
        cout <<"\n"<<i+1<<"."<<ac[i] << endl;
        //Inicio de las comparaciones
if(ac[i]=="Soy redonda como una pelota, vuelo en el cielo y tengo rayos en el pelo. ¿Quién soy?"){

		 cout<<"a) Avestruz b) Avión c) Astronauta"<<endl;
		 cout<<"Responde:"<<endl;cin>>r[i];
		 if(r[i]=="B" || r[i]=="b"){
		 	cout<<"Respuesta correcta"<<endl;
		 	a++;
		 } 	
		 else{
		 cout<<"Respuesta incorrecta"<<endl;	
		 }
}

else if(ac[i]=="Puedo correr sin tener piernas, pero siempre me detengo al llegar a la meta. ¿Qué soy?"){

	 cout<<"a) Un carro b) Un río c) Un reloj"<<endl;
	 cout<<"Responde:"<<endl;cin>>r[i];
	 if(r[i]=="c" || r[i]=="C"){
	 	cout<<"Respusta correcta"<<endl;
	 	a++;
	 }
	 else{
	 	cout<<"Respuesta correcta"<<endl;
	 }
}

else if(ac[i]=="Si me nombras, desaparezco. ¿Qué soy?"){
	cout<<"a) El silencio b) El eco c) El eco"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i]; 
	
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
}
}

else if(ac[i]=="Me puedes partir en pedazos, pero siempre estaré completo. ¿Qué soy?"){

	cout<<"a) Un espejo b) Un corazón c) Un libro"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}

else if(ac[i]=="Si me necesitas, me desechas. Si no me necesitas, me guardas. ¿Qué soy?"){

	cout<<"a) Un secreto b) El dinero c) Un amigo"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
		
	}
}
else if(ac[i]=="Tengo ciudades pero no calles, bosques pero no árboles, y ríos pero no agua. ¿Qué soy?"){
	cout<<"a) Un mapa b) Una fotografía c) Un sueño"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Tengo llaves pero no puertas, tengo espacio pero no habitaciones. ¿Qué soy?"){
cout<<"a) Un estacionamiento b) Un teclado c) Un cofre"<<endl;
cout<<"Responde:"<<endl;cin>>r[i];
if(r[i]=="b" || r[i]=="B"){
	cout<<"Respuesta correcta"<<endl;
	a++;
}
else{
	cout<<"Respuesta incorrecta"<<endl;
}
}
else if(ac[i]=="Cuanto más me quitas, más grande me vuelvo. ¿Qué soy?"){
	cout<<"a) El frío b) Un agujero c) La oscuridad"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B)"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Tengo ojos pero no veo, tengo piernas pero no camino. ¿Qué soy?"){
	cout<<"a) Una cama b) Un muñeco c) Un plátano"<<endl;
	cout<<"Responde"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Tengo ciudades pero no países, ríos pero no agua, y montañas pero no tierra. ¿Qué soy?"){
	cout<<"a) Un planeta b) Un mapa c) Un libro de geografía"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta "<<endl;
		a++;
	}
	else {
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Siempre estoy delante del pasado, pero detrás del futuro. ¿Qué soy?"){
	cout<<"a) La memoria b) Un espejo c) El presente"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else {
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="No hablo, no tengo garganta, pero todos me entienden. ¿Qué soy?"){
	cout<<"a) El pensamiento b) Un libro c) El lenguaje"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Subo cuando el agua baja, pero me ahogo cuando sube. ¿Qué soy?"){
	cout<<"a) Un barco b) Una piedra c) Un globo"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else {
		cout<<"Respuesta incorrecta"<<endl;}
}
else if(ac[i]=="Siempre estoy en el aire, pero nunca me ves. ¿Qué soy?"){
	cout<<"a) El oxígeno b) El viento c) Un pensamiento"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuestaa correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Todos me quieren, todos me buscan, pero cuando me encuentran, me desechan. ¿Qué soy?"){
	cout<<"a) La felicidad b) El amo c) El dinero"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Soy un número de dos cifras. Si me sumas con mi inverso, el resultado siempre es 11. ¿Qué número soy?"){
	cout<<"a) 99 b) 44 c) 55"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Tengo ojos pero no veo, tengo agua pero no me mojo. ¿Qué soy?"){
	cout<<"a) Una botella b) Un pez c) Un puente"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Siempre corro pero nunca camino, tengo boca pero no hablo. ¿Qué soy?"){
	cout<<"a) Un río b) Un reloj c) Un carro"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Soy alto cuando soy joven, pero bajo cuando soy viejo. ¿Qué soy?"){
	cout<<"a) Un árbol b) Un vaso c) Un globo"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(ac[i]=="Tengo manos pero no puedo aplaudir, tengo un rostro pero no puedo sonreír. ¿Qué soy?"){
cout<<"a) Un reloj b) Una máscara c) Una muñeca"<<endl;
cout<<"Responde:"<<endl;cin>>r[i];
if(r[i]=="b" || r[i]=="B"){
	cout<<"Respuesta correcta"<<endl;
	a++;
}
else{
	cout<<"Respueta incorrecta"<<endl;
}
}

} //for

//Puntuacion:Acertijos 
	cout<<"\nPuntucion final :"<<a<<endl;
if(a>=1 && a<=5){
	cout<<"Echale coco"<<endl;
}
else if(a>=6 && a<=8){
	cout<<"Bueno :(";
}
else if(a==0){
	cout<<"Se te va a aparecer el paletas en la noche .";
}
else{
	cout<<"Ta bien "<<endl;
}
//Extra
string o;
cout<<"\n-------------------------------------------";
cout<<"\n1.Regresar al menu principal.";
cout<<"\n2.Salir.";
cout<<"\nQue quieres hacer:";cin>>o;
if(o=="1"){
	repite=false;
}
else if(o=="2"){
		exit(0);
}
	

else if(o!="1" && o!="2"){
	cout<<"\nVuelve a intentarlo";
	
}
getch();
}while(repite);
}
//Fin acertijos ####################################################################


//Logica matemnatica $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void matematica(){
	bool repite= true;
	do{
	
		system("cls");
    			string r[20];
    			int a=0;
    		gotoxy(45,1);	cout<<"-----Acertijos-----"<<endl;

    srand(time(0));

    string lm[20] = {
    "Si Juan tiene el doble de la edad de Pedro, y la suma de sus edades es 36. ¿Cuál es la edad de Pedro?",
        "Si 3 gatos atrapan 3 ratones en 3 minutos, ¿cuántos gatos se necesitarían para atrapar 100 ratones en 100 minutos?",
        "Si un cubo tiene una arista de longitud 5 cm, ¿cuál es su volumen?",
        "Si un número aumenta en un 20% y luego disminuye en un 20%, ¿cuál es el efecto neto en el número?",
        "Si un tren recorre 120 km/h durante 2 horas, ¿cuántos kilómetros ha recorrido en total?",
        "Si un ángulo agudo mide la mitad de un ángulo obtuso, ¿cuánto mide el ángulo obtuso?",
        "Si un vaso contiene 250 ml de agua y se vacía un tercio de su contenido, ¿cuántos mililitros quedan en el vaso?",
        "Si una caja contiene 12 manzanas y se sacan 3 manzanas, ¿qué fracción representa la cantidad de manzanas que quedan en la caja?",
        "Si 5 personas pueden completar un trabajo en 10 días, ¿cuántos días tomará completar el mismo trabajo con 10 personas?",
        "Si un triángulo equilátero tiene un perímetro de 18 cm, ¿cuál es la longitud de cada uno de sus lados?",
        "Si A es el padre de B, y B es el padre de C, ¿quién es el abuelo de C?",
        "Si x + 3 = 7, ¿cuál es el valor de x?",
        "Si un número es divisible por 2 y 3, ¿es necesariamente divisible por 6?",
        "Si un círculo tiene un diámetro de 10 cm, ¿cuál es su radio?",
        "Si 2x + 5 = 13, ¿cuál es el valor de x?",
        "Si un número es divisible por 4 y 5, ¿es necesariamente divisible por 20?",
        "Si un ángulo mide 90 grados, ¿es necesariamente un ángulo recto?",
        "Si un número es divisible por 6 y 9, ¿es necesariamente divisible por 3?",
        "Si un cuadrado tiene un área de 25 cm², ¿cuál es la longitud de uno de sus lados?",
        "Si 2/3 de un número es igual a 8, ¿cuál es el número?"
    };

    random_shuffle(begin(lm), end(lm));

    for (int i = 0; i < 10; i++ ) {
        cout <<"\n"<<i+1<<"."<<lm[i]<< endl;
    //Comparaciones 
if(lm[i]=="Si Juan tiene el doble de la edad de Pedro, y la suma de sus edades es 36. ¿Cuál es la edad de Pedro?"){
	cout<<"a) 12 b) 18 c) 24"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si 3 gatos atrapan 3 ratones en 3 minutos, ¿cuántos gatos se necesitarían para atrapar 100 ratones en 100 minutos?"){
cout<<"a) 1 b) 10 c) 100"<<endl;
cout<<"Responde:"<<endl;cin>>r[i];
if(r[i]=="a" || r[i]=="A"){
	cout<<"Respuesta correcta"<<endl;
	a++;
}
else{
	cout<<"Respuesta incorrecta"<<endl;
}
}
else if(lm[i]=="Si un cubo tiene una arista de longitud 5 cm, ¿cuál es su volumen?"){
	cout<<"a) 15 cm³ b) 25 cm³ c) 125 cm³"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un número aumenta en un 20% y luego disminuye en un 20%, ¿cuál es el efecto neto en el número?"){
	cout<<"a) Aumenta un 20% b) Disminuye un 20% c) No hay cambio"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
cout<<"Respuesta correcta"<<endl;
a++;	
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un tren recorre 120 km/h durante 2 horas, ¿cuántos kilómetros ha recorrido en total?"){
	cout<<"a) 120 km b) 240 km c) 360 km"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un ángulo agudo mide la mitad de un ángulo obtuso, ¿cuánto mide el ángulo obtuso?"){
	cout<<"a) 45° b) 90° c) 180°"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta  incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un vaso contiene 250 ml de agua y se vacía un tercio de su contenido, ¿cuántos mililitros quedan en el vaso?"){
	cout<<"a) 83 ml b) 125 ml c) 167 ml"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si una caja contiene 12 manzanas y se sacan 3 manzanas, ¿qué fracción representa la cantidad de manzanas que quedan en la caja?"){
	cout<<"a) 1/2 b) 1/3 c) 3/4"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="c" || r[i]=="C"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
	}
else if(lm[i]=="Si 5 personas pueden completar un trabajo en 10 días, ¿cuántos días tomará completar el mismo trabajo con 10 personas?"){
	cout<<"a) 5 días b) 10 días c) 20 días"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
			if(r[i]=="b" || r[i]=="B"){
			cout<<"Respuesta correcta"<<endl;
			a++;
		}
		else{
			cout<<"Respuesta inccorrecta"<<endl;
		}
}
else if(lm[i]=="Si un triángulo equilátero tiene un perímetro de 18 cm, ¿cuál es la longitud de cada uno de sus lados?"){
	cout<<"a) 3 cm b) 6 cm c) 9 cm"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si A es el padre de B, y B es el padre de C, ¿quién es el abuelo de C?"){
	cout<<"a) A b) B c) No se puede determinar"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
	}
else if(lm[i]=="Si x + 3 = 7, ¿cuál es el valor de x?"){
	cout<<"a) 3 b) 4 c) 7"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un número es divisible por 2 y 3, ¿es necesariamente divisible por 6?"){
	cout<<"a) Sí b) No c) Depende del número"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un círculo tiene un diámetro de 10 cm, ¿cuál es su radio?"){
	cout<<"a) 5 cm b) 10 cm c) 20 cm"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si 2x + 5 = 13, ¿cuál es el valor de x?"){
	cout<<"a) 4 b) 6 c) 9"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respueesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un número es divisible por 4 y 5, ¿es necesariamente divisible por 20?"){
	cout<<"a) Sí b) No c) Depende del número"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un ángulo mide 90 grados, ¿es necesariamente un ángulo recto?"){
	cout<<"a) Sí b) No c) Depende del contexto"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
		}
		else{
			cout<<"Respueta incorrecta"<<endl;
		}
}
else if(lm[i]=="Si un número es divisible por 6 y 9, ¿es necesariamente divisible por 3?"){
	cout<<"a) Sí  b) No c) Depende del número"<<endl;
	cout<<"Respobde:"<<endl;cin>>r[i];
	if(r[i]=="a" || r[i]=="A"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si un cuadrado tiene un área de 25 cm², ¿cuál es la longitud de uno de sus lados?"){
	cout<<"a) 5 cm b) 10 cm c) 25 cm"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="A" || r[i]=="a"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
}
else if(lm[i]=="Si 2/3 de un número es igual a 8, ¿cuál es el número?"){
	cout<<"a) 6 b) 12 c) 24"<<endl;
	cout<<"Responde:"<<endl;cin>>r[i];
	if(r[i]=="b" || r[i]=="B"){
		cout<<"Respuesta correcta"<<endl;
		a++;
	}
	else{
		cout<<"Respuesta incorrecta"<<endl;
	}
	}
}//for
//Puntuacion:Logica matematica
cout<<"\nPuntucion final :"<<a<<endl;
if(a>=1 && a<=5){
	cout<<"Echale coco"<<endl;
}
else if(a>=6 && a<=8){
	cout<<"Bueno :(";
}
else if(a==0){
	cout<<"Se te va a aparecer el paletas en la noche .";
}
else{
	cout<<"Ta bien "<<endl;
}
//Extraa
cout<<"\n-------------------------------------------------------------";
 string o;
cout<<"\n1.Regresar al menu principal.";
cout<<"\n2.Salir.";
cout<<"\nQue quieres hacer:";cin>>o;
if(o=="1"){
	repite=false;
}
else if(o=="2"){
		exit(0);
}
	

else if(o!="1" && o!="2"){
	cout<<"\nVuelve a intentarlo";
	
}

getch();
}while(repite);
}
//Fin:Logica Matematica $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	
	//Menu///////////////////////////////////////
void menu()
{
 
	bool repite= true;
	  int opcion;
do{
	

system("cls");
	SetConsoleOutputCP(437);
	pintar_limites();
	SetConsoleOutputCP(65001);
    gotoxy(50, 6);
    cout<<"----- MENU -----";
    gotoxy(50, 7);  
	cout << "1. Deportes";
    gotoxy(50, 8);
    cout << "2. Historia" ;
    gotoxy(50, 9);
    cout << "3. Química" ;
    gotoxy(50, 10);
    cout << "4. Acertijos" ;
    gotoxy(50, 11);
    cout << "5. Logica Matematica"    ;
	gotoxy(50, 12);
    cout << "6. Configuración";
	gotoxy(50,13);cout<<"7.Regresar a Stress Ravine";
    gotoxy(50,14);cout<<"8.Salir (del programa)";

    gotoxy(50, 16);
    cout << "Ingrese el número de la opción deseada: ";
    cin >> opcion;
switch(opcion){
	case 1 :
		deportes();
		break;
	case 2:
		historia();
		break;
	case 3:
		quimica();
		break;
	case 4:
		acertijos();
		break;
	case 5:
		matematica();
		break;
	case 6:
		configuracion();
		break;
	case 7:
		repite=false;
		break;
	case 8:
		exit(1);
		break;
			default:
		cout<<"Opcion invalidad vuelve a intentarlo";
	}
}while(repite);
}
//Fin menu%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//Configuracion
void configuracion(){
	bool repite=true;
	
	do{	
		system("cls");
		SetConsoleOutputCP(437);
		pintar_limites();
		SetConsoleOutputCP(65001);
		string o;
		gotoxy(40,8);cout<<"-----Configuración-----";
		gotoxy(40,9);cout<<"1.Cambiar colores";
		gotoxy(40,11);cout<<"2.Regresar al menu principal";
		gotoxy(40,12);cout<<"Elige la opcion: ";cin>>o;
		
		if(o=="1"){
	bool repite_colores = true;
		while(repite_colores){
		

			system("cls");
			SetConsoleOutputCP(437);
			pintar_limites();
			SetConsoleOutputCP(65001);
			string color;
			gotoxy(50,1);cout<<"-----Cambiar colores-----";
			gotoxy(10,6);cout<<"1)Fondo blanco y letras azules";
			gotoxy(10,11);cout<<"2)Fondo verde y letra blanca";
			gotoxy(10,16);cout<<"3)Fondo azul marino y letras rojas";
			gotoxy(50,6);cout<<"4)Fondo rosa y letras negras";
			gotoxy(50,11);cout<<"5)Fondo purpura y letras amarillas";
			gotoxy(50,16);cout<<"6)Fondo amrillo  claro y letras grises";
			gotoxy(40,21);cout<<"7)Regresar a la configuración";
			gotoxy(45,24);cout<<"Elige la opción :";cin>>color;
			
			if(color=="1"){
				system("color F4");
				cout<<CYAN;
                repite=false;
                break;
                
				}
			else if(color=="2"){
				system("color A4");
				cout<<WHITE;
				repite=false;
				break;
			
			}
			else if(color=="3"){
				system("color B4");
				cout<<ORANGE;
				repite=false;
				break;
			}
			else if(color=="4"){
				system("color C4");
				cout<<BLACK;
				repite=false;
				break;
			}
			else if(color=="5"){
				 
				system("color D4");
				cout<<YELLOW;
				repite=false;
				break;
			}
			else if(color=="6"){
				system("color E4");
				cout<<GRAY;
				repite=false;
				break;
				
			}
			else if(color=="7"){
				repite_colores=false;
				break;
			}
}
}
			
		
		else if(o=="3"){
			repite = false;
			break;
			}
	

getch();
}while(repite);
}


 
//TRIVIA FIN ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.......................


void letrero_trivia(int x, int y){
	gotoxy(x,y);cout <<GREEN<< "                                                      \n";
    gotoxy(x,y+1);cout <<GREEN<< "                                                      \n";
    gotoxy(x,y+2);cout <<GREEN<< "                 .--..----.     .----..--.           \n";
    gotoxy(x,y+3);cout <<GREEN<< "                 |__| \\    \\   /    / |__|           \n";
    gotoxy(x,y+4);cout <<GREEN<< "     .|  .-,.--. .--.  '   '. /'   /  .--.           \n";
    gotoxy(x,y+5);cout <<GREEN<< "   .' |_ |  .-. ||  |  |    |'    /   |  |    __     \n";
    gotoxy(x,y+6);cout <<GREEN<< " .'     || |  | ||  |  |    ||    |   |  | .:--.'.   \n";
    gotoxy(x,y+7);cout <<GREEN<< "'--.  .-'| |  | ||  |  '.   `'   .'   |  |/ |   \\ |  \n";
    gotoxy(x,y+8);cout <<GREEN<< "   |  |  | |  '- |  |   \\        /    |  |`\" __ | |  \n";
    gotoxy(x,y+9);cout <<GREEN<< "   |  |  | |     |__|    \\      /     |__| .'.''| |  \n";
    gotoxy(x,y+10);cout <<GREEN<< "   |  '.'| |              '----'          / /   | |_ \n";
    gotoxy(x,y+11);cout <<GREEN<< "   |   / |_|                              \\ \\._,\\ '/ \n";
    gotoxy(x,y+12);cout <<GREEN<< "   `'-'                                    `--'  `\"  \n";
}
 void trivia_main() 
{
	cout<<GREEN;
SetConsoleOutputCP(437);
  pintar_limites();
  letrero_trivia(31,6);
  SetConsoleOutputCP(65001);
gotoxy(40,19); cout<<"PRESIONE CUALQUIER TECLA PARA INICIAR"<<endl;
getch();
cout<<CYAN;
menu();
}

//HEAD AND LEAD INICIO &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&66666666666

void headlead_main() {
	bool gameover_head_n_lead;
	bool main=true;
	string us;
	int menu;
	int repetir;
	int hijito, furia, matar_Anna;
    int desicion, posible_final1,segundadesicion_sn,estilo, pelear_entregar,consolar,nazi,rodear_derrotar, anterior_con_nazi, granadaMatar, destruir;
while (main){
		SetConsoleOutputCP(437);
		cout<<RED;

		cout <<RED<< "____    ____                       ___                               ___       ____                            ___" << endl;
        cout << "`MM'    `MM'                       `MM                               `MM       `MM'                            `MM" << endl;
        cout << " MM      MM                         MM                                MM        MM                              MM" << endl;
        cout << " MM      MM   ____      ___     ____MM          ___   ___  __     ____MM        MM        ____      ___     ____MM" << endl;
        cout << " MM      MM  6MMMMb   6MMMMb   6MMMMMM        6MMMMb  `MM 6MMb   6MMMMMM        MM       6MMMMb   6MMMMb   6MMMMMM" << endl;
        cout << " MMMMMMMMMM 6M'  `Mb 8M'  `Mb 6M'  `MM       8M'  `Mb  MMM9 `Mb 6M'  `MM        MM      6M'  `Mb 8M'  `Mb 6M'  `MM" << endl;
        cout << " MM      MM MM    MM     ,oMM MM    MM           ,oMM  MM'   MM MM    MM        MM      MM    MM     ,oMM MM    MM" << endl;
        cout << " MM      MM MMMMMMMM ,6MM9'MM MM    MM       ,6MM9'MM  MM    MM MM    MM        MM      MMMMMMMM ,6MM9'MM MM    MM" << endl;
        cout << " MM      MM MM       MM'   MM MM    MM       MM'   MM  MM    MM MM    MM        MM      MM       MM'   MM MM    MM" << endl;
        cout << " MM      MM YM    d9 MM.  ,MM YM.  ,MM       MM.  ,MM  MM    MM YM.  ,MM        MM    / YM    d9 MM.  ,MM YM.  ,MM" << endl;
        cout << "MM    MM YMMMM9  `YMMM9'Yb.YMMMMMM_      `YMMM9'Yb_MM_  MM YMMMMMM_      MMMMMMM  YMMMM9  `YMMM9'Yb.YMMMMMM" << endl;
        SetConsoleOutputCP(65001);
		
		cout<<endl<<"1. JUGAR"<<endl;
		cout<<"2. REGRESAR A STRESS RAVINE"<<endl;
		cin>>menu;
		
		switch(menu){
		case 1:
		system("cls");
		cout << WHITE<<"¿Cuál es el nombre del héroe?"<<endl;
		cin >> us;
		gameover_head_n_lead=false;
		break;
		
		case 2:
			main=false;
			gameover_head_n_lead=true;
			system("cls");
		break;
		
		default: cout<<endl<<"INGRESE UNA OPCIÓN VÁLIDA"<<endl; system("cls"); main=true;
		
	}
   	while (!gameover_head_n_lead) {


	
	
		cout << "Empiezas a abrir tus ojos lentamente, apenas puedes sentir pocas partes de tu cuerpo."<<endl;
		cout << "Tu respiración está muy agitada y solo escuchas una voz a lo lejos."<<endl;
		Sleep(4000);
	    cout <<MAGENTA<<"???: "<<us<<", "<<us<<"..."<<endl;
	    Sleep (4000);
		cout <<WHITE<<"Solo puedes ver la figura de una mujer alta con una gran sonrisa en la cara."<<endl;
		cout<<" "<<endl;
		cout<<MAGENTA<< "???: ¿Te encuentras bien?"<<endl;
		cout<<GRAY<<"1-. ¿Quién eres? ¿Dónde estoy?"<<endl; 
		cout<<"2-. Seee..."<<endl;
		cin>>desicion;

		//INICIO DESICION INICIAL
		if(desicion==1){ //¿qN ERES?
			cout<<MAGENTA<<"Anna: Ay Dios si que fue grave el impacto. El cirujano dijo que era muy"<<endl;
			cout<<"      probable que perdieras gran parte de tu memoria. Soy Anna, trabajo"<<endl;
			cout<<"      como enfermera en el batallón A113 para el ejercito americano."<<endl;
			cout<<"      Tu eres "<<us<<" y eres soldado en este mismo pelotón, no lo recuerdas"<<endl;
			cout<<"      pero somos grandes amigos desde que eramos niños."<<endl;
			cout<<"   "<<endl;
			Sleep (5000);
		}
		
		else { //SEEE
			cout<<MAGENTA<<"???: ¿Cuánto es 3x7?"<<endl;
		    Sleep (3000);
			cout<<GRAY<<us<<": Ammm..."<<endl;
			Sleep (100);
			cout<<MAGENTA<<"???: Jaja tontito."<<endl;
			Sleep (1000);
			cout<<"Anna: Debes de estar confundido por el accidente, apenas sobreviviste."<<endl;
			cout<<"      Tú eres "<<us<<" estás en el pelotón A113. Yo soy Anna, soy enfermera aquí"<<endl;
			cout<<"      no lo recuerdas pero eramos amigos desde niños."<<endl;
			Sleep (10000);
		} //FIN DESICION INICIAL
		
		cout<<"Anna: Ahora mismo tenemos un infiltrado entre nuestras"<<endl;
	    cout<<"      tropas, pero yo tengo información que ningún otro"<<endl;
        cout<<"      soldado o comandante tiene..."<<endl;
    	Sleep (10000);
	
        cout<<GRAY<<"1-. ¿Qué es lo que sabes?"<<endl; 
	    cout<<"2-. No me importa loser"<<endl; 
	    cin>>posible_final1;
	    //INICIO POSIBLE FINAL 1
	    //¿QUÉ ES LO Q SABES?
	    if(posible_final1==1){
	    	cout<<MAGENTA<<"Anna: Tengo que saber si vas a venir..."<<endl;
		    Sleep (3000);
		    cout<<GRAY<<us<<": Muy bien, voy a ir."<<endl;
		    Sleep (2000);
		    cout<<MAGENTA<<"Anna: Ven a verme en la noche y te diré todo el plan"<<endl;
		    Sleep(5000);
		    cout<<WHITE<<"Más tarde ese mismo día, Anna y tu se encuentran en el lugar acordado."<<endl;
			Sleep(4000);
			cout<<MAGENTA<<"Anna: Muy bien, tenemos que salir de aqui."<<endl;
			cout<<GRAY<<"1-. ¿Cómo saldrémos?"<<endl;
			cout<<"2-. ¿Por qué?"<<endl;
			cin>>segundadesicion_sn;
			
			//INICIO SEGUNDA DESICION SN
			//COMO SALDREMOS
			if(segundadesicion_sn==1){
				cout<<"Anna: Vamos a robar un auto del almacen, tengo una mochila con"<<endl;
				cout<<"      armas, munición, comida y más equipamento."<<endl;
				Sleep (4000);
			} //FIN COMO SALDREMOS
			//POR QUE
			else{
				cout<<"Anna; ¿Quieres que nos descubran?"<<endl;
				cout<<"       Te lo diré luego, sígueme..."<<endl;
			} //FIN POR QUE
			
			
		cout<<GRAY<<"Llegan con facilidad a un gran almacen. Y al entrar pueden ver"<<endl;
		cout<<"una gran colección de autos y transportes."<<endl;
		
		cout<<MAGENTA<<"Anna: ¿Cómo saldremos de aquí?"<<endl;
		cout<<"  "<<endl;
		Sleep(1000);
		cout<<GRAY<<"1-. Estilo Rambo "<<endl;
		cout<<"2-. Encallado "<<endl;
		cin>>estilo;
		
		//INICIO ESTILO
		//ESTILO RAMBO
		if(estilo==1){
			cout<<GRAY<<us<<": Vamos a explotar el lugar... "<<endl;
			Sleep(2000);
		    cout<<MAGENTA<<"Anna: ¿Estás loco?"<<endl;
		    Sleep (2000);
		    cout<<GRAY<<us<<": Es la única manera de salir de aquí"<<endl;
		    cout<<"      ¿Tienes una mejor idea?"<<endl;
		    Sleep (2000);
		    cout<<MAGENTA<<"Anna: Okey... Espero que funcioné."<<endl;
		    Sleep (1000);
		    cout<<WHITE<<"Anna y tu empiezan a derramar litros de gasolina por todo"<<endl;
		    cout<<"el almacen, mientras que Anna sube todas las cosas a una"<<endl;
		    cout<<"camioneta."<<endl;
		    cout<<"  "<<endl;
		    Sleep (3000);
		    cout<<MAGENTA<<"Anna: Muy bien, ahora... ¿Cuál es tu plan genio?"<<endl;
		    Sleep (1000);
		    cout<<GRAY<<us<<": Voy a abrir el portón y tu saldrás a toda velocidad,"<<endl;
		    cout<<"      yo desde afuera lanzaré un cerillo. Eso explotará el"<<endl;
		    cout<<"      lugar y espero que no lo haga conmigo."<<endl;
		    cout<<"      Tu regresas por mí y salimos de este lugar."<<endl;
		    cout<<"  "<<endl;
		    Sleep (1000);
		    cout<<MAGENTA<<"Anna: A trabajar!!"<<endl;
		    Sleep (1000);
		    cout<<WHITE<<"Anna sube al auto, mientras que tu abres la puerta y esperas"<<endl;
		    cout<<"la señal de Anna. Ella arranca rapidamente el auto, mientras"<<endl;
		    cout<<"que tu sueltas el portón e inicias el incendio."<<endl;
		    cout<<"Con solo el contacto de la flama todo el almacen explota y por"<<endl;
		    cout<<"pelo logras salir intacto."<<endl;
		    cout<<"  "<<endl;
		    Sleep (2000);
		    cout<<"Sales corriendo lo más rapido que puedes, (Sigues estando cojo)"<<endl;
		    cout<<"mientras de fondo suena una alarma alertando a todo el pelotón."<<endl;
		    cout<<"No puedes ver a Anna en ningún lado y sigues corriendo. Hasta"<<endl;
		    cout<<"que en cierto punto puedes ver a Anna rodeada de unos soldados."<<endl;
		    cout<<" "<<endl;
		    Sleep (1000);
		    
		    cout<<GREEN<<"¿Que harás?"<<endl;
		    cout<<"1-. Pelear "<<endl;
		    cout<<"2-. Entregarte"<<endl;
		    cin>>pelear_entregar;
		    //INICIO PELEAR ENTREGAR
		    //PELEAR
		    if(pelear_entregar==1){
		    	cout<<WHITE<<"Ves unicamente a 4 soldados, solo puedes sentir furia,"<<endl;
		    		cout<<"por un momento recuerdas todo lo que has perdido. Esta"<<endl;
		    		cout<<"guerra te quitó todo lo que amas..."<<endl;
		    		cout<<" "<<endl;
		    		Sleep (6000);
		    		cout<<"Te lanzas contra soldado, ya no quieres esto. La venganza"<<endl;
		    		cout<<"se va apoderando de ti. Despúes de noquearlo con solo tus"<<endl;
		    		cout<<"puños, los demas soldados van contra ti, pero tu raccionas"<<endl;
		    		cout<<"mucho más rapido y los matas con un disparo certero."<<endl;
		    		cout<<" "<<endl;
		    		Sleep (6000);
                    cout<<us<<": Salgamos de aquí Anna..."<<endl;
                    Sleep (1000);
                    cout<<MAGENTA<<"Anna: Okey..."<<endl;
                    cout<<WHITE<<"Dice algo atormentada. Ambos suben a la camioneta y se"<<endl;
                    cout<<"despinden del lugar rapidamente."<<endl;
                    cout<<" "<<endl;
                    Sleep(7000);
                    cout<<"Puedes ver a Anna muy nerviosa por lo sucedido, intentas"<<endl;
                    cout<<"hablar de lo sucedido, pero tienes un nudo en la garganta."<<endl;
                    Sleep (2000);
                    cout<<MAGENTA<<"Anna: Con respecto a lo que pasó... Esta bien, solo me asusté"<<endl;
                    cout<<"      un poco. No me pude imaginar a ti matando de esa manera."<<endl;
                    cout<<WHITE<<"1-. Lo lamento no se que me sucedió, simplemente me sentí furioso."<<endl;
                    cout<<"2-. No decir nada"<<endl;
                    cin>>consolar;
                    //INICIO CONSOLAR
                    //LAMENTARSE
                    if(consolar==1){
                    	cout<<MAGENTA<<"Anna: No te preocupes igual yo me siento así muchas veces. La"<<endl;
                    		cout<<"      verdad quiero que todo este conflicto se acabe, odio estar"<<endl;
                    		cout<<"      aquí. No me refiero a estar aquí contigo, me refiero a la"<<endl;
                    		cout<<"      guerra."<<endl;
                    		Sleep (3000);
                    		cout<<WHITE<<us<<": Gracias, Anna."<<endl;
                    		cout<<"Le das una sonrisa inspiradora a Anna y continua su camino."<<endl;
                    		Sleep(4000);
					}//FIN LAMENTARSE
					
					else { //NO DECIR NADA
						cout<<"Puedes ver una mirada de decepción en la cara de Anna, te sientes un"<<endl;
						    cout<<"poco culpable, pero no le das importancia."<<endl;
							Sleep(3000);    
						    break;

					} //FIN NO DECIR NADA
	
			}//FIN PELEAR
			
			else { //ENTREGARSE //POSIBLE tercer FINAL
				cout<<WHITE<<"Llegas a donde esta Anna con los brazos levantados, te"<<endl;
                	cout<<"puedes sentir un poco nervioso y miras la preocupación"<<endl;
                	cout<<"en la mirada de Anna."<<endl;
                	cout<<" "<<endl;
                	Sleep (4000);
                	cout<<MAGENTA<<"Anna: ¿"<<us<<"qué estás haciendo?"<<endl;
                	Sleep (1000);
                	cout<<GRAY<<us<<": Lo necesario..."<<endl;
                	cout<<"  "<<endl;
                	Sleep (1000);
                	cout<<"Los soldados te agarran contra la pared y puedes escuchar"<<endl;
                	cout<<"llantos provenientes de Anna."<<endl;
                	cout<<" "<<endl;
                	Sleep (1000);
                	cout<<us<<": Esperen..."<<endl;
                	cout<<"Un soldado te dispara en la cabeza y termina contigo..."<<endl;
                	cout<<"  "<<endl;
                	cout<<"                  Logro debloqueado: 'La paz nunca fue una opción'"<<endl;
                	cout<<"                                                  FIN"<<endl;
                	gameover_head_n_lead=true;
                	cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");

			}//FIN ENTREGARSE //FIN tercer POSIBLE FINAL


		}//FIN ESTILO RAMBO
		
		//ESTILO ENCALLADO
			else {
				      cout<<GRAY<<us<<": Tomaremos un auto y saldremos por la entrada"<<endl;
			  cout<<"      principal como si nada."<<endl;
			  cout<<"  "<<endl;
			  Sleep (2000);
			  cout<<MAGENTA<<"Anna: ¿Estás seguro que funcionará? "<<endl;
			  cout<<"  "<<endl;
			  Sleep (1000);
			  cout<<GRAY<<us<<": Claro que va a funcionar... Te conocen a ti,"<<endl;
			  cout<<"      me conocen a mi. Solo diremos que nos necesitan"<<endl;
			  cout<<"      en otra base de operación."<<endl;
			  cout<<" "<<endl;
			  Sleep (5000);
			  cout<<"Ambos suben al auto y se dirigen a la salida principal,"<<endl;
			  cout<<"al llegar los encuentra un guardía."<<endl;
			  cout<<"  "<<endl;
			  Sleep (3000);
			  cout<<RED<<"Guardía 1: Buenas noches Dra. Johnson ¿A donde va tan noche?"<<endl;
			  Sleep (2000);
			  cout<<MAGENTA<<"Anna: Me enviaron a ver un paciente en la base de Berlín."<<endl;
			  Sleep (2000);
			  cout<<RED<<"Guardía 1: Muy bien, sigan adelante."<<endl;
			  Sleep (2000);
			  cout<<WHITE<<"El vehiculo sale del centro de operación y se dirige a hacia"<<endl;
			  cout<<"el horizonte."<<endl;
			  cout<<" "<<endl;
			  Sleep (1000);
				
			} //FIN DE ENCALLADO
		    //FIN ESTILOS
		
			cout<<WHITE<<"Despúes de conducir durante un par de horas ambos llegan a un pequeño pueblo"<<endl;
		    cout<<"alemán. Ahí se establecen una pequeña base en una casa abandonada."<<endl;
		    cout<<" "<<endl;
		    Sleep(2000);
		    cout<<us<<": ¿Ya me vas a decir que es lo sucede en el pelotón?"<<endl;
		    cout<<MAGENTA<<"Anna: Ohh cierto... lo olvide."<<endl;
		    cout<<"      Según la información que me llegó, el "<<RED<<"General Morden"<<endl;
			cout<<MAGENTA<<"      es un nazi infiltrado. El intententa destruir nuestro batallón desde dentro."<<endl;
			Sleep (4000);
			cout<<WHITE<<us<<": Ohh... ya veo."<<endl;
			cout<<" "<<endl;
			cout<<"Al pasar la noche te despiertas por unos fuertes gritos provenientes en el centro"<<endl;
			cout<<"del pueblo. Rapidamente agarras una arma y despiertas a Anna sacudiendo su cuerpo"<<endl;
			cout<<"fuertemente mientras que gritas su nombre."<<endl;
			cout<<" "<<endl;
			Sleep (7000);
			cout<<us<<": ANNA!! ANNA!! Vamos despierta."<<endl;
			Sleep (3000);
			cout<<MAGENTA<<"Anna: ¿Qué pasa"<<us<<"?"<<endl;
			cout<<us<<WHITE<<": Se- se escuchan gritos tenemos que ir a ver."<<endl;
			cout<<MAGENTA<<"Anna: Muy bien, vamos."<<endl;
			cout<<WHITE<<"Ambos agarran sus mochilas y salen corriendo hacia donde se escuchan los"<<endl;
			cout<<"gritos. Al llegar pueden ver a un grupo de soldados alemánes torturando a"<<endl;
			cout<<"otro soldado nazi. Solo escuchas un montón de palabras desconocidas para ti."<<endl;
			cout<<"Al pasar unos minutos los nazis cuelgan en un arbol a esa rata y rapidamente"<<endl;
			cout<<"ellos huyen."<<endl;
			cout<<" "<<endl;
			Sleep (12000);
			cout<<"Lo unico que escuchas es como ese nazi intenta respirar."<<endl;
			cout<<" "<<endl;
			Sleep (3000);
			cout<<MAGENTA<<"Anna: "<<us<<" debemos salvarlo"<<endl;
			cout<<WHITE<<"1-. Claro que no, no salvaremos un nazi"<<endl;
			cout<<"2-. Muy bien lo salvaremos"<<endl;
			cin>>nazi;
			//INICIO NAZI
			//NO lo SALVAREMOS
			if(nazi==1){
			cout<<us<<": Es un nazi, no sabes a cuantos de nuestros compañeros ha matado."<<endl;
			Sleep (2000);
			cout<<MAGENTA<<"Anna: Pero... Nada, olvidalo."<<endl;
			cout<<" "<<endl;
			cout<<WHITE<<"Anna y tu dejan morir al soldado, viendo como se quedaba sin aire"<<endl;
			cout<<"puedes ver la cara aterrorizada de Anna."<<endl;
			cout<<" "<<endl;
			cout<<us<<": Debemos continuar..."<<endl;
			Sleep (3000);
			cout<<"Ambos agarran su equipo y salen de ahi. Al caminar por el pueblo pueden ver"<<endl;
			cout<<"un pequeño ejército de alemánes siendo escoltados por un gran tanque de guerra."<<endl;
			cout<<" "<<endl;
			Sleep (5000);
			cout<<GREEN<<"1-. Rodear el tanque "<<endl;
			cout<<"2-. Derrotar a todos "<<endl;
			cin>>hijito;
				//INICIO RODEAR DERROTA
				//RODEAR
				if(hijito==1){
					cout<<WHITE<<us<<": Okey, vamos a rodear el tanque y no haremos ruido. Así no nos"<<endl;
				    cout<<"     van a descubrir."<<endl;
				    cout<<" "<<endl;
				    cout<<"Los dos van rodeando la cuadra evitando a cualquier nazi, caminando de "<<endl;
				    cout<<"manera sigilosa. "<<endl;
				    cout<<" "<<endl;
				    Sleep (5000);
				    cout<<us<<": Muy bien Anna ¿Dónde tenemos que ir?"<<endl;
				    cout<<MAGENTA<<"Anna: Tenemos que recoger unos documentos como evidencia para"<<endl;
				    cout<<"      exponer al general Morden y evitar que destruya nuestro"<<endl;
				    cout<<"      pelotón. Esos papeles estan es su base la cual es la"<<endl;
				    cout<<"      iglesia del pueblo."<<endl;
				    cout<<" "<<endl;
				    Sleep (3000);
				    cout<<WHITE<<"Anna y tu se van acercando cada vez más. Hasta ahora la misión"<<endl;
				    cout<<"ha sido relativamente sencilla, pero de repente se escucha una"<<endl;
				    cout<<"gran explosión."<<endl;
				    cout<<" "<<endl;
				    Sleep (4000);
				    cout<<"¡Es el mismo tanque que estaban evitando todo este tiempo!"<<endl;
				    cout<<"Tu única idea es agarrar la mano de Anna y correr hacia la casa más cercana"<<endl;
				    cout<<"y resguardarse por un poco de tiempo."<<endl;
				    cout<<" "<<endl;
				    Sleep (3000);
				    cout<<us<<": No tenemos mucho tiempo Anna, tenemos que correr hacia la iglesia sin"<<endl;
				    cout<<"      importar que."<<endl;
				    cout<<" "<<endl;
				    cout<<"Ustedes salen corriendo de ahí, mientras el tanque va demoliendo todo a su paso."<<endl;
				    cout<<"No paran de correr, solo sientes como los misiles del tanque te rosan tu cuerpo"<<endl;
				    cout<<"y te aturde el estrepitoso sonido de las explosiones, siguen siendo perseguidos"<<endl;
				    cout<<"por el tanque hasta llegar a la iglesia."<<endl;
				    cout<<" "<<endl;
				    Sleep (6000);
				    cout<<MAGENTA<<"Anna: Rápido busca la carpeta con los documentos, yo revisaré por"<<endl;
				    cout<<         "      aquí. Tu busca en todos los lados que puedas, pero para ayer"<<endl;
				    cout<<WHITE<<us<<": Como digas jefa..."<<endl;
				    cout<<" "<<endl;
				    cout<<"Empiezas buscar por todos los estantes y muebles de la iglesia, solo sientes"<<endl;
				    cout<<"como el suelo tiembla. El tanque ya casi llega, tu sigues buscando el documento"<<endl;
				    cout<<"cuando encuentras una carpeta roja con el nombre 'Morden' el tanque destruye la"<<endl;
				    cout<<"la entrada."<<endl;
				    cout<<" "<<endl;
				    Sleep (7000);
				    cout<<us<<": Corre!!!"<<endl;
				    cout<<" "<<endl;
				    cout<<"Anna y tu salen por la puerta trasera de la iglesia pero al correr caen en un pequeño"<<endl;
				    cout<<"socavón. El tanque pasa por arriba de la iglesia destruyendola por completo. Y al "<<endl;
				    cout<<"parecer no pueden verlos. El tanque pasa por arriba del hoyo y tu abres la escotilla"<<endl;
				    cout<<"de escape y lanzas una granada adentro para matar a los conductores."<<endl;
				    Sleep (5000);
				    cout<<MAGENTA<<"Anna: No sé como pero lo lograste!!"<<endl;
				    
				    
                    }
                    
			      else{//DERROTAR
					cout<<WHITE<<us<<": Okey... vamos a destruir ese tanque"<<endl;
					cout<<MAGENTA<<"Anna: ¿Cómo lo se supone que lo harás?"<<endl;
					cout<<WHITE<<us<<": Pondremos una distracción para llamar la atención del"<<endl;
					cout<<"  tanque, despúes instalaremos unas minas para inmovilizarlo."<<endl;
					cout<<"  Luego me entrare por la escotilla de escape y lanzaré una granada"<<endl;
					cout<<"  nada complicado..."<<endl;
					cout<<" "<<endl;
					Sleep (7000);
					cout<<"La distracción era que Anna matara a los soldados de la ultima línea,"<<endl;
					cout<<"mientras que tu preparas las minas para destruir las orugas"<<endl;
					cout<<"del tanque pero a lo lejos puedes ver algo a lo lejos..."<<endl;
					cout<<" "<<endl;
					Sleep (5000);
					cout<<"Anna fue lastimada por una bala, el tanque se va moviendo en reversa"<<endl;
					cout<<"mientras que tiene a Anna en la mira. Tu rapidamente corres hacia el"<<endl;
					cout<<"tanque y te subes arriba de el y noqueas al soldado que controla la"<<endl;
					cout<<"torreta exterior. "<<endl;
					Sleep (4000);
					cout<<GREEN<<"¿Que harás?"<<endl;
					cout<<"1-. Matar a los del tanque con una granada"<<endl;
					cout<<"2-. Usar la torreta para ayudar a Anna con los soldados"<<endl;
					cin>>destruir;
					//Inicio de destruir
					//Matar nazis con granada		
					if (destruir==1){
						cout<<WHITE<<"Abres la escotilla del tanque y lanzas 2 granadas de mano,"<<endl;
				        cout<<"al cerrar la escotilla escuchas los gritos de los alemanes"<<endl;
				        cout<<" "<<endl;
				        Sleep (2000);
				        cout<<"Saltas del tanque y rapidamente vas disparando a los soldados"<<endl;
				        cout<<"que están llendo a por Anna."<<endl;
				        cout<<"Tu llegas al edificio donde está escondida Anna, solo esperas"<<endl;
				        cout<<"que ella esté bien. Cuando de repente recibes un disparo en la"<<endl;
				        cout<<"pierna. Caes al suelo y solo puedes ver la silueta de un soldado."<<endl;
				        cout<<" "<<endl;
				        Sleep (7000);
				        cout<<"El nazi comienza a golpearte y burlarse de ti, estas muy debil,"<<endl;
				        cout<<"que ni siquiera te puedes mover, cuando de repente..."<<endl;
				        cout<<" "<<endl;
				        Sleep (3000);
				        cout<<"Anna sale y le dispara al soldado por la espalda"<<endl;
				        cout<<MAGENTA<<"Anna: ¿Te encuentras bien?"<<endl;
				        cout<<WHITE<<"Anna te ayuda con tus heridas y tu ayudas a Anna con las suyas,"<<endl;
				        cout<<"al ayudarla ella te sonrie y puedes escuchar un 'gracias' con un"<<endl;
				        cout<<"voz rota y con un tomo muy bajo."<<endl;
				        cout<<" "<<endl;
				        Sleep (5000);
				        cout<<us<<": Salgamos de aquí..."<<endl;

				        
					 }	
					    //Fin de destruir granada
					 else { //Ayudar AA
						cout<<WHITE<<"Despúes de noquear al soldado, te subes a la torreta del tanque"<<endl;
						cout<<"y empiezas a disparar a todos los soldados, derribando a casi "<<endl;
						cout<<"todos los soldados nazis."<<endl;
						cout<<" "<<endl;
						Sleep (4000);
						cout<<"Cuando se te acaban las balas, saltas del tanque y empiezas a"<<endl;
						cout<<"corre hacia donde está Anna. Pero una gran explosión te aturde."<<endl;
						cout<<"Eso era el mismo tanque que te disparaba con el cañon mientas"<<endl;
						cout<<"que iba de reversa, tu corrias esquivando las explosiones a tu"<<endl;
						cout<<"alrededor. Y tu apenas llegaste intacto."<<endl;
						cout<<" "<<endl;
						Sleep (5000);
						cout<<"Al llegar puedes ver a Anna cubriendose con una mesa. La puedes"<<endl;
						cout<<"ver muy herida."<<endl;
						cout<<" "<<endl;
						cout<<us<<": Anna... ¿Te encuentras bien?"<<endl;
						cout<<MAGENTA<<"Anna: No te preocupes, la he pasado peor jeje..."<<endl;
						cout<<WHITE<<"Rampidamente ayudas a Anna, extrayendo la bala del brazo de Anna"<<endl;
						cout<<"vendas su herida y la ayudas a levantarse."<<endl;
						cout<<" "<<endl;
						cout<<us<<": Salgamos de aquí..."<<endl;
						Sleep (7000);
						cout<<"Al salir pueden como el tanque explota por las minas que colocaste."<<endl;
					
					}
					//Fin de ayudar AA
				    cout<<us<<": ¿A donde debemos de ir ahora?"<<endl;
					cout<<MAGENTA<<"Anna: En la iglesia hay unos documentos que necesitamos para"<<endl;
					cout<<"      inculpar al general Morden."<<endl;
					Sleep (4000);
					cout<<WHITE<<"Anna y tu se dirigen hacia la iglesia sin mayor complicaciones y"<<endl;
					cout<<"recogen una carpeta roja con el nombre 'MORDEN'"<<endl;
					
				}	 
				//Inicio de final "malo"
				    cout<<us<<": Salgamos de aqui..."<<endl;
				    cout<<" "<<endl;
				    cout<<"Ustedes vuelven a su vehículo y se ponen en marcha para volver a la base"<<endl;
				    cout<<"A113. Ustedes saben que ya no seran bienvenidos con los brazos abiertos,"<<endl;
				    cout<<"por eso tendrán que meterse a escondidas en la oficina del Teniente Miler"<<endl;
				    cout<<" "<<endl;
				    Sleep (5000);
				    cout<<MAGENTA<<"Anna: ¿Cómo es que dejaremos los documentos?"<<endl;
				    cout<<WHITE<<us<<": Mmmm... supongo que tendremos que improvisar."<<endl;
				    cout<<" "<<endl;
				    Sleep (3000);
				    cout<<"Logran meterse a la base por una pequeña malla rota por la parte"<<endl;
				    cout<<"derecha, mientras ayudas a Anna para entrar puedes escuchar la  "<<endl;
				    cout<<"alarma avisando su llegada."<<endl;
				    cout<<" "<<endl;
				    cout<<GREEN<<"¿Qué haras?"<<endl;
				    cout<<"1-. Esconderte"<<endl;
				    cout<<"2-. Matar a todos"<<endl;
				    cin>>furia;
				    if (furia==1){//inicio de esconderte
				    	 cout<<WHITE<<"Anna y tu se separan por caminos distintos, no sabes"<<endl;
				    	 cout <<"que hacer solo sientes miedo."<<endl;
				    	 cout<<" "<<endl;
				    	 Sleep (3000);
				    	 cout<<"Realmente no eres tan fuerte como creías, te quedas"<<endl;
				    	 cout<<"totalmente paralizado cuando llegan los soldados, no"<<endl;
				    	 cout<<"sabes que hacer. Levantas tus manos y te rindes."<<endl;
				    	 cout<<" "<<endl;
				    	 Sleep (5000);
				    	 cout<<RED<<"            Logro debloqueado: 'Verdadero miedo'"<<endl;
				    	 cout     <<"                              FIN"<<endl;
				    	 gameover_head_n_lead=true;
				    	 cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");
					}
					//Fin de esconderte 
					
					else {//Inicio de matar a todos
						cout<<WHITE<<"Odias a todo el mundo, ya no quieres estar ahí solo"<<endl;
						cout<<"quieres saber quien eras tu antes que todo esto"<<endl;
						cout<<"empezara."<<endl;
						cout<<" "<<endl;
						Sleep (4000);
						cout<<"Sales de tu escondite y empiezas a disparar a todos los"<<endl;
						cout<<"soldados que ves. Ya no te importa nada, ni siquiera Anna."<<endl;
						cout<<"Llegas hasta la oficina del Teniente Miler. Pero ahí te"<<endl;
						cout<<"esperaba una gran sorpresa..."<<endl;
						cout<<" "<<endl;
						Sleep (7000);
						cout<<"Era el General Morden..."<<endl;
						Sleep (2000);
						cout<<"Te lanzas contra el y con tu navaja empiezas a apuñalarlo"<<endl;
						cout<<"no tienes autocontrol. Nada te puede parar, pero de la "<<endl;
						cout<<"nada ves una sombra acercarse... ¿Será un problema? "<<endl;
						cout<<" "<<endl;
						cout<<RED<<"¿Que harás?"<<endl;
						cout<<"1-. Relajarte"<<endl;
						cout<<"2-. Disparar"<<endl;
						cin>>matar_Anna;
						if (matar_Anna==1){ //Inicio de relajarte
							cout<<WHITE<<"Al escuchar como se abria la puerta decides calmarte"<<endl;
							cout<<       "antes de hacer una estupidez. "<<endl;
							cout<<" "<<endl;
							Sleep (3000);
							cout<<"Ves a Anna entrar, al verte ella camina hacia ti y te da un fuerte abrazo."<<endl;
							cout<<" "<<endl;
							Sleep (3000);
							cout<<"                  Logro desbloqueado: Aún tienes salvación."<<endl;
							cout<<"                                       FIN"<<endl;
							gameover_head_n_lead=true;
							cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");
							
						} //Fin de relajarte 
						
						else {
							cout<<WHITE<<"Ya no quieres hacer nada por este mundo. Así que decides disparar."<<endl;
							cout<<"Al atacar te das cuenta lo que hiciste, le has disparado a Anna."<<endl;
							cout<<" "<<endl;
							Sleep (4000);
							cout<<"Al terminar con tu unica razón de vivir ya no tienes más esperanzas,"<<endl;
							cout<<"asi que decides acabar con tu miserable vida de un disparo a la cabeza"<<endl;
							cout<<" "<<endl;
							Sleep (4000);
							cout<<RED<<"                   Logro desbloqueado: 'No tienes remedio"<<endl;
							cout<<"                                      FIN"<<endl;
							gameover_head_n_lead=true;
							cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");
						}
						//Fin de disparar
						
						
						
					}//Fin de matar a todos
				    
			    } //FIN DEJAR MORIR
			
			else{ //LO SALVAREMOS
				cout<<"Rapidamente con tu navaja cortas la cuerda y el cuerpo debil del soldado"<<endl;
				cout<<"cae al suelo."<<endl;
				cout<<" "<<endl;
				Sleep (4000);
				cout<<us<<": Muy bien Güerito levantate, arriba."<<endl;
				cout<<MAGENTA<<"Anna: Hola amigo, soy Anna."<<endl;
				cout<<" "<<endl;
				Sleep (6000);
				cout<<ORANGE<<"???: Was für eine schöne Frau, Anna hat einen Ehemann?"<<endl;
				Sleep (5000);
				cout<<WHITE<<"Anna y tu se quedan confundidos por lo que dijo ya que no"<<endl;
				cout<<"entendieron nada de lo que el dijo. Tu le das una hoja de"<<endl;
				cout<<"papel y una pluma al nazi para que escriba su nombre."<<endl;
				cout<<"El soldado los agarra y empieza a escribir. Te devuelve"<<endl;
				cout<<"la nota y y ves que dice 'Herman'"<<endl;
				cout<<" "<<endl;
				Sleep(10000);
				cout<<MAGENTA<<"Anna: Que lindo nombre Herman"<<endl;
				cout<<ORANGE<<"Herman: Guten Tag..."<<endl;
				cout<<" "<<endl;
				Sleep (4000);
				cout<<WHITE<<us<<": Vamos a salir de aqui."<<endl;
				cout<<" "<<endl;
				cout<<"Anna cura las heridas de Herman colocando unos cuantos vendajes cuidadosamente, al"<<endl;
				cout<<"terminar ayudas a levantar a Herman y salen de ahí. Unas cuadras despúes ustedes"<<endl;
				cout<<"pueden ver a un gran tanque de batalla escoltando a un pequeño pelotón de soldados."<<endl;
				cout<<" "<<endl;
				Sleep (5000);
				cout<<GREEN<<"¿Qué harás?"<<endl;
				cout<<"1-. Destruir el tanque"<<endl;
				cout<<"2-. Rodear el tanque"<<endl; 
				cin>>anterior_con_nazi;
			    //Inicio de derrotar con nazi
			    //Destruir el tanque
				if (anterior_con_nazi==1){
					cout<<WHITE<<us<<": Okey... vamos a destruir ese tanque"<<endl;
					cout<<MAGENTA<<"Anna: ¿Como  se supone que lo harás?"<<endl;
					cout<<WHITE<<us<<": Pondremos una distracción para llamar la atención del"<<endl;
					cout<<"  tanque, despúes instalaremos unas minas para inmovilizarlo."<<endl;
					cout<<"  Luego me adentrare por la escotilla de escape y lanzaré una granada"<<endl;
					cout<<"  nada complicado..."<<endl;
					cout<<" "<<endl;
					Sleep (7000);
					cout<<"La distracción era que Anna matara a los soldados de la ultima línea,"<<endl;
					cout<<"mientras que tu y Herman preparan las minas para destruir las orugas"<<endl;
					cout<<"del tanque pero a lo lejos puedes ver algo a lo lejos..."<<endl;
					cout<<" "<<endl;
					Sleep (5000);
					cout<<"Anna fue lastimada por una bala, el tanque se va moviendo en reversa"<<endl;
					cout<<"mientras que tiene a Anna en la mira. Tu rapidamente corres hacia el"<<endl;
					cout<<"tanque y te subes arriba de el y noqueas al soldado que controla la"<<endl;
					cout<<"torreta exterior. "<<endl;
					Sleep (4000);
					cout<<GREEN<<"¿Que harás?"<<endl;
					cout<<"1-. Matar a los del tanque con una granada"<<endl;
					cout<<"2-. Usar la torreta para ayudar a Anna con los soldados"<<endl;
					cin>>granadaMatar;
					//Inicio de granadaMatar
					//Matar nazis con granada		
					if (granadaMatar==1){
						cout<<WHITE<<"Abres la escotilla del tanque y lanzas 2 granadas de mano,"<<endl;
				        cout<<"al cerrar la escotilla escuchas los gritos de los alemanes"<<endl;
				        cout<<" "<<endl;
				        Sleep (2000);
				        cout<<"Saltas del tanque y rapidamente vas disparando a los soldados"<<endl;
				        cout<<"que están llendo a por Anna."<<endl;
				        cout<<"Tu llegas al edificio donde está escondida Anna, solo esperas"<<endl;
				        cout<<"que ella esté bien. Cuando de repente recibes un disparo en la"<<endl;
				        cout<<"pierna. Caes al suelo y solo puedes ver la silueta de un soldado."<<endl;
				        cout<<" "<<endl;
				        Sleep (7000);
				        cout<<"El nazi comienza a golpearte y burlarse de ti, estás muy debil,"<<endl;
				        cout<<"que ni siquiera te puedes mover, cuando de repente..."<<endl;
				        cout<<" "<<endl;
				        Sleep (3000);
				        cout<<"Anna sale y le dispara al soldado por la espalda"<<endl;
				        cout<<MAGENTA<<"Anna: ¿Te encuentras bien?"<<endl;
				        cout<<WHITE<<"Anna te ayuda con tus heridas y tu ayudas a Anna con las suyas,"<<endl;
				        cout<<"al ayudarla ella te sonrie y puedes escuchar un 'gracias' con un"<<endl;
				        cout<<"voz rota y con un tomo muy bajo."<<endl;
				        cout<<" "<<endl;
				        Sleep (5000);
				        cout<<us<<": Salgamos de aquí..."<<endl;
				        

				        
					 }	
					//Fin de matar con granada
					else { //Ayudar a Anna
						cout<<WHITE<<"Despúes de noquear al soldado, te subes a la torreta del tanque"<<endl;
						cout<<"y empiezas a disparar a todos los soldados, derribando a casi "<<endl;
						cout<<"todos los soldados nazis."<<endl;
						cout<<" "<<endl;
						Sleep (4000);
						cout<<"Cuando se te acaban las balas, saltas del tanque y empiezas a"<<endl;
						cout<<"corre hacia donde está Anna. Pero una gran explosión te aturde."<<endl;
						cout<<"Eso era el mismo tanque que te disparaba con el cañon mientas"<<endl;
						cout<<"que iba de reversa, tu corrías esquivando las explosiones a tu"<<endl;
						cout<<"alrededor. Y tu apenas llegaste intacto."<<endl;
						cout<<" "<<endl;
						Sleep (5000);
						cout<<"Al llegar puedes ver a Anna cubriendose con una mesa. La puedes"<<endl;
						cout<<"ver muy herida."<<endl;
						cout<<" "<<endl;
						cout<<us<<": Anna... ¿Te encuentras bien?"<<endl;
						cout<<MAGENTA<<"Anna: No te preocupes, la he pasado peor jeje..."<<endl;
						cout<<"Rampidamente ayudas a Anna, extrayendo la bala del brazo de Anna"<<endl;
						cout<<"vendas su herida y la ayudas a levantarse."<<endl;
						cout<<" "<<endl;
						cout<<us<<": Salgamos de aquí..."<<endl;
						Sleep (7000);
						cout<<"Al salir pueden ver como el tanque explota por las minas que colocaron"<<endl;
						cout<<"tu y Herman."<<endl;
						Sleep (3000);
						
					    }
					    //Fin de ayudar a Anna
					    cout<<us<<": ¿A donde debemos de ir ahora?"<<endl;
					    cout<<MAGENTA<<"Anna: En la iglesia hay unos documentos que necesitamos para"<<endl;
					    cout<<"      inculpar al general Morden."<<endl;
					    cout<<WHITE<<"Ustedes se dirigen hacia la iglesia sin mayor complicaciones y"<<endl;
					    cout<<       "recogen una carpeta roja con el nombre 'MORDEN'"<<endl;
					    }
                        //Fin de destruir tanque
                        else {
                    	cout<<WHITE<<us<<": Okey, vamos a rodear el tanque y no haremos ruido. Así no nos"<<endl;
				        cout<<"     van a descubrir."<<endl;
				        cout<<"Todos ustedes van rodeando la cuadra evitando a cualquier nazi, "<<endl;
				        Sleep (5000);
				        cout<<us<<": Muy bien Anna ¿Dónde tenemos que ir?"<<endl;
				        cout<<MAGENTA<<"Anna: Tenemos que recoger unos documentos como evidencia para"<<endl;
				        cout<<"      exponer al general Morden y evitar que destruya nuestro"<<endl;
				        cout<<"      pelotón. Esos papeles estan es su base la cual es la"<<endl;
				        cout<<"      iglesia del pueblo."<<endl;
				        cout<<" "<<endl;
				        Sleep (3000);
				        cout<<WHITE<<"Ustedes se van acercando cada vez más. Hasta ahora la misión"<<endl;
				        cout<<"ha sido relativamente sencilla, pero de repente se escucha una"<<endl;
				        cout<<"gran explosión."<<endl;
				        cout<<" "<<endl;
				        Sleep (4000);
				        cout<<"¡Es el mismo tanque que estaban evitando todo este tiempo!"<<endl;
				        cout<<"Tu unica idea es agarrar la mano de Anna y correr hacia la casa más cercana"<<endl;
				        cout<<"y resguardarse por un poco de tiempo. No te importa lo que pasó con Herman,"<<endl;
				        cout<<"solo importa que Anna esta bien. Pero al poco rato el entra con ustedes."<<endl;
				        cout<<" "<<endl;
				        Sleep (6000);
				        cout<<us<<": No tenemos mucho tiempo Anna, tenemos que correr hacia la iglesia sin"<<endl;
				        cout<<"      importar que."<<endl;
				        cout<<" "<<endl;
				        cout<<"Ustedes salen corriendo de ahí, mientras el tanque va demoliendo todo a su paso."<<endl;
				        cout<<"No paran de correr, solo sientes como los misiles del tanque te rosan tu cuerpo"<<endl;
				        cout<<"y te aturden el estrepitoso sonido de las explosiones, siguen siendo perseguidos"<<endl;
				        cout<<"por el tanque hasta llegar a la iglesia."<<endl;
				        cout<<" "<<endl;
				        Sleep (6000);
				        cout<<MAGENTA<<"Anna: Rápido busca la carpeta con los documentos, yo revisaré por"<<endl;
				        cout<<         "      aquí. Tu busca en todos los lados que puedas, pero para ayer."<<endl;
				        Sleep (3000);
				        cout<<WHITE<<us<<": Como digas jefa..."<<endl;
				        cout<<" "<<endl;
				        cout<<"Empiezas buscar por todos los estantes y muebles de la iglesia, solo sientes"<<endl;
				        cout<<"como el suelo tiembla. El tanque ya casi llega, tu sigues buscando el documento"<<endl;
				        cout<<"cuando encuentras una carpeta roja con el nombre 'Morden' el tanque destruye la"<<endl;
				        cout<<"la entrada."<<endl;
				        cout<<" "<<endl;
				        Sleep (7000);
				        cout<<us<<": Corre!!!"<<endl;
				        cout<<" "<<endl;
				        cout<<"Anna y tu salen por la puerta trasera de la iglesia pero al correr caen en un pequeño"<<endl;
				        cout<<"socavón. El tanque pasa por arriba de la iglesia destruyendola por completo. Y al "<<endl;
				        cout<<"parecer no pueden verlos. El tanque pasa por arriba del hoyo y tu abres la escotilla"<<endl;
				        cout<<"de escape y lanzas una granada adentro para matar a los conductores."<<endl;
				        Sleep (5000);
				        cout<<MAGENTA<<"Anna: No sé como pero lo lograste!!"<<endl;
				        
						
					
					    }
					    //FIN SALVAR
				        cout<<us<<": Salgamos de aqui..."<<endl;
				        cout<<" "<<endl;
				        cout<<"Ustedes vuelven a su vehículo y se ponen en marcha para volver a la base"<<endl;
				        cout<<"A113. Ustedes saben que ya no seran bienvenidos con los brazos abiertos,"<<endl;
				        cout<<"por eso tendrán que meterse a escondidas en la oficina del Teniente Miler"<<endl;
				        cout<<" "<<endl;
				        Sleep (5000);
                        cout<<MAGENTA<<"Anna: ¿Cómo es que dejaremos los documentos?"<<endl;
				        cout<<WHITE<<us<<": Mmmm... supongo que tendremos que improvisar."<<endl;
				        cout<<" "<<endl;
				        Sleep (3000);
				        cout<<"Logran meterse a la base por una pequeña malla rota por la parte"<<endl;
				        cout<<"derecha, mientras ayudas a Anna y a Herman para entrar puedes escuchar la  "<<endl;
				        cout<<"alarma avisando su llegada."<<endl;
				        cout<<" "<<endl;
				        Sleep (5000);
                        cout<<"Anna y Herman se separan de tí, no tuienes idea donde podrían estar."<<endl;
                        cout<<"Todo esto sucede mientras que los soldados se dirigen hacia tu posición."<<endl;
                        cout<<" "<<endl;
                        Sleep (3000);
                        cout<<"Cuando están por llegar Herman lanza una granada para llamar la atención"<<endl;
                        cout<<"de los soldados."<<endl;
                        cout<<" "<<endl;
                        Sleep (3000);
                        cout<<"Esto te da tiempo para correr hacia la oficina del Teniente Miler,"<<endl;
                        cout<<"al llegar puedes ver al Comandante Morden."<<endl;
                        Sleep (3000);
                        cout<<RED<<"Comandante Morden: Wow asi que lo descubriste... Nada mal."<<endl;
                        cout<<WHITE<<us<<": ¿Que quiere de mi?"<<endl;
                        cout<<RED<<"Comandante Morden: Quiero que veas de lo que es capaz de hacer la"<<endl;
                        cout<<"                   Raza Aria."<<endl;
                        cout<<WHITE<<us<<": Jamás"<<endl;
                        cout<<" "<<endl;
                        Sleep (3000);
                        cout<<"Te lanzas contra el y para ser justos el te esta matando."<<endl;
                        cout<<"No hay nada que puedas hacer, ya esta muy debil. "<<endl;
                        cout<<"Pero de la nada el general morden recibe una bala en el pecho"<<endl;
                        cout<<"proveniente de Anna."<<endl;
                        cout<<" "<<endl;
                        Sleep (5000);
                        cout<<"Herman te ayuda a levantarte y tre sonrie."<<endl;
                        cout<<"Anna: Lo logramos"<<us<<", no se como pero lo hicimos."<<endl;
                        Sleep (3000);
                        cout<<"Anna te da un fuerte abrazo y se van hacia el horizonte."<<endl;
                        cout<<" "<<endl;
                        cout<<GREEN<<"                     Logro debloqueado: Salvación"<<endl;
                        cout<<"                                      FIN"<<endl;
                        gameover_head_n_lead=true;
                        cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");
		            } //FIN NAZI
			


		


		}//FIN POSIBLE FINAL1 QUÉ ES LO QUE SABES
		
		//FINAL 2 NO ME IMPORTA
		else{
			cout<<MAGENTA<<"Anna: Lo haré yo sola, gracias."<<endl;
		    Sleep (2000);
		    cout<<"   "<<endl;
		    cout<<RED<<"          Logro debloqueado: 'Tus necesidades no son problema mio'"<<endl;
		        
		    cout<<"                                 FIN"<<endl;
		    gameover_head_n_lead=true;
		    cout<<endl<<"¿Desea explorar otros finales?"<<endl;
				    	 cout<<"SÍ (1) NO, REGRESAR A SR (2)";
				    	 cin>>repetir;
				    	 if(repetir==1) main=true;
				    	 else main=false;
				    	 system("cls");

		} //FIN POSIBLE FINAL 2 NO ME IMPORTA

		
		

	}
}
}
//HEAD AND LEAD FIN&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&66666666666

//PAINT ++ INICIO ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????''''''
void letrero_paint (int x, int y){
	
	pintar_limites();
	y++; gotoxy(x,y);cout <<YELLOW<< "                                     ___                                " << endl;   //ROJO
    y++; gotoxy(x,y);cout <<YELLOW<< "                    .-.             (   )                               " << endl;	//ROJO
    y++; gotoxy(x,y);cout <<YELLOW<< "   .-..     .---.  ( __)  ___ .-.    | |_           .-.         .-.     " << endl;	//ROJO
    y++; gotoxy(x,y);cout <<RED<< "  /    \\   / .-, \\ (''') (   )   \\  (   __)         | |         | |     " << endl; //CYAN
    y++; gotoxy(x,y);cout <<RED<< " ' .-,  ; (__) ; |  | |   |  .-. .   | |        .---| |---. .---| |---. " << endl;	//CYAN
    y++; gotoxy(x,y);cout <<RED<< " | |  . |   .'`  |  | |   | |  | |   | | ___    '---| |---` '---| |---` " << endl;	//CYAN
    y++; gotoxy(x,y);cout <<GREEN<< " | |  | |  / .'| |  | |   | |  | |   | |(   )       | |         | |     " << endl;	//VERDE
    y++; gotoxy(x,y);cout <<GREEN<< " | |  | | | /  | |  | |   | |  | |   | | | |        '-'         '-'     " << endl;	//VERDE
    y++; gotoxy(x,y);cout <<BLUE<< " | |  ' | ; |  ; |  | |   | |  | |   ' '-' ;                            " << endl;	//NARANJA
    y++; gotoxy(x,y);cout <<BLUE<< " | `-'  ' ' `-'  |  | |   | |  | |   ' `-' ;                            " << endl;	//NARANJA
    y++; gotoxy(x,y);cout <<BLUE<< " | \\__.'  `.__.'_. (___) (___)(___)   `.__.                             " << endl; //MORADO
    y++; gotoxy(x,y);cout <<MAGENTA<< " | |                                                                    " << endl; //MORADO
    y++; gotoxy(x,y);cout <<MAGENTA<< "(___)";
}


class PINCEL {
	int x,y;
public:
PINCEL(int _x, int _y):x(_x),y(_y){}
void paint_w(char n);
void paint_d(char n);
};

void PINCEL::paint_w(char n){ 

if(kbhit()){
	 	char tecla=getch();
	 		
	 		if (tecla=='j' && x>3) x--;
	 		if (tecla=='l' && x <114 ) x++;
	 		if(tecla=='k' && y<26 )y++;
	 		if (tecla=='i' && y>4)y--;
	 	
	 			
			 	
			 	if (GetAsyncKeyState('2') & 0x8000){
	 			gotoxy(x,y); cout<<RED<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('3') & 0x8000){
	 			gotoxy(x,y); cout<<YELLOW<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('4') & 0x8000){
	 			gotoxy(x,y); cout<<BLUE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('5') & 0x8000){
	 			gotoxy(x,y); cout<<GREEN<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('6') & 0x8000){
	 			gotoxy(x,y); cout<<ORANGE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('7') & 0x8000){
	 			gotoxy(x,y); cout<<ROSE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('8') & 0x8000){
	 			gotoxy(x,y); cout<<MAGENTA<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('9') & 0x8000){
	 			gotoxy(x,y); cout<<CYAN<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('0') & 0x8000){
	 			gotoxy(x,y); cout<<GRAY<<n;
			 	}
			 	

			 	if (GetAsyncKeyState('1') & 0x8000){
	 			gotoxy(x,y); cout<<BLACK<<n;
			 	}
			 	if (GetAsyncKeyState('B') & 0x8000){
	 			gotoxy(x,y); cout<<WHITE<<n;
			 	}
			 	
			 	else {
			 	gotoxy(x,y); cout<<n;
			 	}
			 	
	 }
}

void PINCEL::paint_d(char n){ //2 DARK

if(kbhit()){
	 	char tecla=getch();
	 		
	 		if (tecla=='j' && x>3) x--;
	 		if (tecla=='l' && x <114 ) x++;
	 		if(tecla=='k' && y<26 )y++;
	 		if (tecla=='i' && y>4)y--;
	 	
	 			
			 	
			 	if (GetAsyncKeyState('2') & 0x8000){
	 			gotoxy(x,y); cout<<RED<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('3') & 0x8000){
	 			gotoxy(x,y); cout<<YELLOW<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('4') & 0x8000){
	 			gotoxy(x,y); cout<<BLUE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('5') & 0x8000){
	 			gotoxy(x,y); cout<<GREEN<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('6') & 0x8000){
	 			gotoxy(x,y); cout<<ORANGE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('7') & 0x8000){
	 			gotoxy(x,y); cout<<ROSE<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('8') & 0x8000){
	 			gotoxy(x,y); cout<<MAGENTA<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('9') & 0x8000){
	 			gotoxy(x,y); cout<<CYAN<<n;
			 	}
			 	
			 	if (GetAsyncKeyState('0') & 0x8000){
	 			gotoxy(x,y); cout<<GRAY<<n;
			 	}
			 	

			 	if (GetAsyncKeyState('B') & 0x8000){
	 			gotoxy(x,y); cout<<BLACK<<n;
			 	}
			 	if (GetAsyncKeyState('1') & 0x8000){
	 			gotoxy(x,y); cout<<WHITE<<n;
			 	}
			 	
			 	else {
			 	gotoxy(x,y); cout<<n;
			 	}
			 	
	 }
}


void paintpp_main() {
	int mode;
	char n;
	bool paint;
	bool paint_execute;
	bool paint_b;
	bool paint_d;
	paint_execute=true;

	
	while (paint_execute){
				system("cls");
				system("color 70");
				letrero_paint(5,8);
				gotoxy(85,12); cout<<BLACK<< "1-	Modo Brillante";
				gotoxy(85,13); cout<<BLACK<< "2-	Modo Oscuro";
				gotoxy(85,14); cout<<BLACK<< "3-	Regresar a Stress Ravine";
				
				gotoxy(85,15);cin>>mode;
				system("cls");
				PINCEL P(60,15);
				paint_b= true;
				paint_d= true;
		 
			switch (mode){
		 	case 3:
		 		paint_execute=false;
		 		paint_b=false;
		 		paint_d=false;
		 		system("cls");
		 		break;
			case 1:
				while(paint_b){
	
					system("color 70");
					SetConsoleOutputCP(437);
					pintar_limites();
					SetConsoleOutputCP(65001);
					n='o';
					gotoxy(1,2); printf("PINCELES || E -> * || R -> o || T -> + || Y -> x ||"); printf("BORRAR/MOVER -> B"); printf("   LIMPIAR PANTALLA -> N");printf(" MENÚ -> M");
					gotoxy(1,28); cout<<RED<<"CO"<<BLUE<<"LO"<<YELLOW<<"RES||"<<BLACK<<" NEGRO (1) ||"<<RED<< " ROJO (2) ||"<<YELLOW<<" AMARILLO (3) ||"<<BLUE<<" AZUL (4)"<<GREEN<<" VERDE (5) ||"<<ORANGE<<" NARANJA (6) ||"<<ROSE<<" ROSA (7) ||"<<MAGENTA<<" MORADO (8) ||"<<endl;
					cout<<CYAN" CYAN (9) ||"<<GRAY<<"GRIS (0) ||"<<BLACK"   ";
					paint=true;
				
					while(paint){
						P.paint_w(n);    
					
					
						if (GetAsyncKeyState('E') & 0x8000) {
							n='*';	
						}
						
						if (GetAsyncKeyState('R') & 0x8000) {
							n='o';
								
						}
						
						if (GetAsyncKeyState('T') & 0x8000) {
							n='+';	
							
						}
						
						if (GetAsyncKeyState('Y') & 0x8000) {
							n='x';	
							
						}
						
						if (GetAsyncKeyState('N') & 0x8000) {
							system("cls");
							paint=false;	
							
						}
						
						
						
						if (GetAsyncKeyState('M') & 0x8000) {
							system("cls");
							system("color 70");
							SetConsoleOutputCP(437);
							pintar_limites();
							Sleep(500);
							paint_b=false;
							paint=false;
							paint_execute=true;		
						}
					
					
						Sleep(30);	
					}	
				}
				break;
			case 2:
				while (paint_d){
				
					system("color 07");
					SetConsoleOutputCP(437);
					pintar_limites();
					SetConsoleOutputCP(65001);
					n='o';
					gotoxy(1,2); printf("PINCELES || E -> * || R -> o || T -> + || Y -> x ||"); printf("BORRAR/MOVER -> B"); printf("   LIMPIAR PANTALLA -> N");printf(" MENÚ -> M");
					gotoxy(1,28); cout<<RED<<"CO"<<BLUE<<"LO"<<YELLOW<<"RES||"<<WHITE<<" BLANCO (1) ||"<<RED<< " ROJO (2) ||"<<YELLOW<<" AMARILLO (3) ||"<<BLUE<<" AZUL (4)"<<GREEN<<" VERDE (5) ||"<<ORANGE<<" NARANJA (6) ||"<<ROSE<<" ROSA (7) ||"<<MAGENTA<<" MORADO (8) ||"<<endl;
					cout<<CYAN" CYAN (9) ||"<<GRAY<<"GRIS (0) ||"<<WHITE<<"   ";
					paint=true;
						
					while(paint){
						P.paint_d(n);    
						
						if (GetAsyncKeyState('E') & 0x8000) {
							n='*';	
						}
						
						if (GetAsyncKeyState('R') & 0x8000) {
							n='o';
								
						}
						
						if (GetAsyncKeyState('T') & 0x8000) {
							n='+';	
							
						}
						
						if (GetAsyncKeyState('Y') & 0x8000) {
							n='x';	
							
						}
						
						if (GetAsyncKeyState('N') & 0x8000) {
							system("cls");
							paint=false;	
							
						}
						
						if (GetAsyncKeyState('M') & 0x8000) {
							system("cls");
							system("color 07");
							SetConsoleOutputCP(437);
							pintar_limites();
							Sleep(500);
							paint_d=false;
							paint=false;
							paint_execute=true;	
								
						}
										
						
							
						Sleep(30);	
					}
				}
			break;
			
		}	
	}
}

//PAINT ++ FIN ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????''''''

//DADOS INICIO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%555555555555555
void letrero_dados(int x, int y){
	gotoxy(x,y);cout << "          _____                    _____                    _____                   _______                   _____          " << endl;
    gotoxy(x,y+1);cout << "         /\\    \\                  /\\    \\                  /\\    \\                 /::\\    \\                 /\\    \\         " << endl;
    gotoxy(x,y+2);cout << "        /::\\    \\                /::\\    \\                /::\\    \\               /::::\\    \\               /::\\    \\        " << endl;
    gotoxy(x,y+3);cout << "       /::::\\    \\              /::::\\    \\              /::::\\    \\             /::::::\\    \\             /::::\\    \\       " << endl;
    gotoxy(x,y+4);cout << "      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\           /::::::::\\    \\           /::::::\\    \\      " << endl;
    gotoxy(x,y+5);cout << "     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\         /:::/~~\\:::\\    \\         /:::/\\:::\\    \\     " << endl;
    gotoxy(x,y+6);cout << "    /:::/  \\:::\\    \\        /:::/  \\:::\\    \\        /:::/  \\:::\\    \\       /:::/    \\:::\\    \\       /:::/__\\:::\\    \\    " << endl;
    gotoxy(x,y+7);cout << "   /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/    \\:::\\    \\     /:::/    / \\:::\\    \\      \\:::\\   \\:::\\    \\   " << endl;
    gotoxy(x,y+8);cout << "  /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/    / \\:::\\    \\   /:::/____/   \\:::\\____\\   ___\\:::\\   \\:::\\    \\  " << endl;
    gotoxy(x,y+9);cout << " /:::/    /   \\:::\\ ___\\  /:::/\\:::\\   \\:::\\    \\  /:::/    /   \\:::\\ ___\\ |:::|    |     |:::|    | /\\   \\:::\\   \\:::\\    \\ " << endl;
    gotoxy(x,y+10);cout << "/:::/____/     \\:::|    |/:::/  \\:::\\   \\:::\\____\\/:::/____/     \\:::|    ||:::|____|     |:::|    |/::\\   \\:::\\   \\:::\\____\\" << endl;
    gotoxy(x,y+11);cout << "\\:::\\    \\     /:::|____|\\::/    \\:::\\  /:::/    /\\:::\\    \\     /:::|____| \\:::\\    \\   /:::/    / \\:::\\   \\:::\\   \\::/    /" << endl;
    gotoxy(x,y+12);cout << " \\:::\\    \\   /:::/    /  \\/____/ \\:::\\/:::/    /  \\:::\\    \\   /:::/    /   \\:::\\    \\/:::/    /   \\:::\\   \\:::\\   \\/____/ " << endl;
    gotoxy(x,y+13);cout << "  \\:::\\    \\ /:::/    /            \\::::::/    /    \\:::\\    \\ /:::/    /     \\:::\\    /:::/    /     \\:::\\   \\:::\\    \\     " << endl;
    gotoxy(x,y+14);cout << "   \\:::\\    /:::/    /              \\::::/    /      \\:::\\    /:::/    /       \\:::\\__/:::/    /       \\:::\\   \\:::\\____\\    " << endl;
    gotoxy(x,y+15);cout << "    \\:::\\  /:::/    /               /:::/    /        \\:::\\  /:::/    /         \\::::::::/    /         \\:::\\  /:::/    /    " << endl;
    gotoxy(x,y+16);cout << "     \\:::\\/:::/    /               /:::/    /          \\:::\\/:::/    /           \\::::::/    /           \\:::\\/:::/    /     " << endl;
    gotoxy(x,y+17);cout << "      \\::::::/    /               /:::/    /            \\::::::/    /             \\::::/    /             \\::::::/    /      " << endl;
    gotoxy(x,y+18);cout << "       \\::::/    /               /:::/    /              \\::::/    /               \\::/____/               \\::::/    /       " << endl;
    gotoxy(x,y+19);cout << "        \\::/____/                \\::/    /                \\::/____/                 ~~                      \\::/    /        " << endl;
    gotoxy(x,y+20);cout << "         ~~                       \\/____/                  ~~                                                \\/____/         " << endl;
    gotoxy(x,y+21);cout<<"                                             PRESIONE 'T' PARA TIRAR"<<endl;
    gotoxy(0,27);cout<<"0 (SALIR)"<<endl;
}

void dado1(int x,int y){
	
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    |     |\n");
    gotoxy(x,y+2);printf("    |  o  |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |_____| \n");
}

void dado2(int x,int y){
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    |     |\n");
    gotoxy(x,y+2);printf("    | o o |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |_____| \n");
}

void dado3(int x,int y){
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    |    o|\n");
    gotoxy(x,y+2);printf("    |  o  |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |o____| \n");
}

void dado4(int x,int y){
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    | o o |\n");
    gotoxy(x,y+2);printf("    | o o |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |_____| \n");
}

void dado5(int x,int y){
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    | o o |\n");
    gotoxy(x,y+2);printf("    |  o  |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |o___o| \n");
}

void dado6(int x,int y){
	gotoxy(x-2,y);printf("       _____\n");
    gotoxy(x,y+1);printf("    | o o |\n");
    gotoxy(x,y+2);printf("    | o o |\n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("    |_o_o_| \n");
}
void borrar_dado(int x,int y){
	gotoxy(x-2,y);printf("                   \n");
    gotoxy(x,y+1);printf("                   \n");
    gotoxy(x,y+2);printf("                   \n");  // Código ASCII decimal
    gotoxy(x,y+3);printf("                   \n");
}

void animacion_dados(int x, int y){
	dado1(x,y);
	Sleep(200);
	borrar_dado(x,y);
	
	dado2(x,y);
	Sleep(200);
	borrar_dado(x,y);
	
	dado3(x,y);
	Sleep(200);
	borrar_dado(x,y);
	
	dado4(x,y);
	Sleep(200);
	borrar_dado(x,y);
	
	dado5(x,y);
	Sleep(200);
	borrar_dado(x,y);
	
	dado6(x,y);
	Sleep(200);

}

void dados_main() {
	OcultarCursor();
	system("color 70");
int dadines=0;
char teclo;
bool jugardados=true;

while(jugardados){

	letrero_dados(0,0);
	if(dadines==0){
	dado1(48,23);
	dado6(63,23);
	dadines=1;
	}
	srand(time(NULL));
	
	if (GetAsyncKeyState('T') & 0x8000){
	
	int dado_a= 1+ rand()%(6-1);
	int dado_b= 1+ rand()%(6-1);
	
	

	animacion_dados(48,23);
	
			//PRIMER DADO	
	if (dado_a==1){
		dado1(48,23);
	}
	
	else if (dado_a==2){
		dado2(48,23);
	}
	
	else if (dado_a==3){
		dado3(48,23);
	}
	
	else if (dado_a==4){
		dado4(48,23);
	}
	
	else if (dado_a==5){
		dado5(48,23);
	}
	
	else if (dado_a==6){
		dado6(48,23);
	}
		
	//SEGUNDO DADO
	
	animacion_dados(63,23);
			
	if (dado_b==1){
		dado1(63,23);
	}
	
	else if (dado_b==2){
		dado2(63,23);
	}
	
	else if (dado_b==3){
		dado3(63,23);
	}
	
	else if (dado_b==4){
		dado4(63,23);
	}
	
	else if (dado_b==5){
		dado5(63,23);
	}
	
	else if (dado_b==6){
		dado6(63,23);
	}
}
	
	if (GetAsyncKeyState('0') & 0x8000){
	 	jugardados=false;
	}
	
	Sleep(30);
	
	
}
}
//DADOS FIN%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5555555555555

void letrero_stress_ravine(int x, int y){
gotoxy(x,y);cout << " ________  _________  ________  _______   ________   ________          " << endl;
gotoxy(x,y+1);cout << "|\\   ____\\|\\___   ___\\\\   __  \\|\\  ___ \\ |\\   ____\\ |\\   ____\\         " << endl;
gotoxy(x,y+2);cout << "\\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\   __/|\\ \\  \\___|_\\ \\  \\___|_        " << endl;
gotoxy(x,y+3);cout << " \\ \\_____  \\   \\ \\  \\ \\ \\   _  _\\ \\  \\_|/\\ \\_____  \\\\ \\_____  \\       " << endl;
gotoxy(x,y+4);cout << "  \\|____|\\  \\   \\ \\  \\ \\ \\  \\\\  \\\\ \\  \\_|/\\|____|\\  \\\\|____|\\  \\      " << endl;
gotoxy(x,y+5);cout << "    ____\\_\\  \\   \\ \\__\\ \\ \\__\\\\ _\\\\ \\_______\\____\\_\\  \\ ____\\_\\  \\     " << endl;
gotoxy(x,y+6);cout << "   |\\_________\\   \\|__|  \\|__|\\|__|\\|_______|\\_________\\\\_________\\    " << endl;
gotoxy(x,y+7);cout << "   \\|_________|                              \\|_________\\|_________|    " << endl;
gotoxy(x,y+8);cout << "                                                                         " << endl;
gotoxy(x,y+9);cout << "                                                                         " << endl;
gotoxy(x,y+10);cout << " ________  ________  ___      ___ ___  ________   _______               " << endl;
gotoxy(x,y+11);cout << "|\\   __  \\|\\   __  \\|\\  \\    /  /|\\  \\|\\   ___  \\|\\  ___ \\              " << endl;
gotoxy(x,y+12);cout << "\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\  /  / | \\  \\ \\  \\\\ \\  \\ \\   __/|             " << endl;
gotoxy(x,y+13);cout << " \\ \\   _  _\\ \\   __  \\ \\  \\/  / / \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|/__           " << endl;
gotoxy(x,y+14);cout << "  \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\    / /   \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\          " << endl;
gotoxy(x,y+15);cout << "   \\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\__/ /     \\ \\__\\ \\__\\\\ \\__\\ \\_______\\         " << endl;
gotoxy(x,y+16);cout << "    \\|__|\\|__|\\|__|\\|__|\\|__|/       \\|__|\\|__| \\|__|\\|_______|         " << endl;

}
int main(int argc, char** argv) 
{
	
	string contrasena;
    string usuario;
    string usuariocorrecto1="Chas";
    string usuariocorrecto2="Tilin";
    string usuariocorrecto3="Parcahot";
    string usuariocorrecto4= "Panchitonalgon";
    string contrasenacorrecta1="Chastilin";
    string contrasenacorrecta2="Tilino";
    string contrasenacorrecta3="pili";
    string contrasenacorrecta4="1234";
    int intentos=0;
    bool contrasena_correcta = false;
    int menu_principal;
    bool consulta=true;
    int seleccion_consulta;

	
  /* do {
   		SetConsoleOutputCP(437);
    	pintar_limites();
    	SetConsoleOutputCP(65001);
        gotoxy(5,4);cout << "Usuario: ";
        cin >> usuario;

        gotoxy(5,5);cout << "Contraseña: ";
        contrasena = "";
        char ch;
        while ((ch = _getch()) != '\r') { // Leer caracteres hasta presionar Enter
            contrasena.push_back(ch);
            cout << "*"; // Mostrar asterisco en lugar del caracter
        }
        cout << endl;

        if (( usuario ==usuariocorrecto1  && contrasena ==contrasenacorrecta1   )  || (usuario ==usuariocorrecto2 && contrasena==contrasenacorrecta2) ||(usuario ==usuariocorrecto3 && contrasena==contrasenacorrecta3) ||(usuario ==usuariocorrecto4 && contrasena==contrasenacorrecta4)) {
            contrasena_correcta = true;
        }
        
        else {
        	intentos++;
        	gotoxy(5,6);cout<<"USUARIO O CONTRASEÑA INVALIDOS, INTENTELO OTRA VEZ";
        	getch();
		}
		
		if(intentos>=3){
			system("cls");
			SetConsoleOutputCP(437);
			pintar_limites();
			SetConsoleOutputCP(65001);
			gotoxy(5,4);cout<<"DEMASIADOS INTENTOS, SE FINALIZARÁ EL PROGRAMA";
			getch();
			system("cls");
			return 0;
		}
		
		system("cls");

    } while (!contrasena_correcta); */
    
    bool stress_ravine=true;
    
    SetConsoleOutputCP(437);
    pintar_limites();
    
    while(stress_ravine){
    	OcultarCursor();
    	letrero_stress_ravine(5,4);
    	SetConsoleOutputCP(65001);
    	gotoxy(90, 5); cout<<"JUEGOS";
    	gotoxy(90, 6); cout<<"1- Space Odessey";
    	gotoxy(90, 7); cout<<"2- Trivia";
    	gotoxy(90, 8); cout<<"3- Head and Lead";
    	gotoxy(90, 9); cout<<"4- Paint++";
    	gotoxy(90, 10); cout<<"5- Dados";
    	
    	gotoxy(90, 12); cout<<"FUNCIONALIDADES";
    	gotoxy(90, 13); cout<<"6- ¿Como jugar?";
    	gotoxy(90, 14); cout<<"7- Ayuda  Contacto";
    	gotoxy(90, 15); cout<<"8- Salir";
    	gotoxy(90, 18); cin>>menu_principal;
    	SetConsoleOutputCP(437);
    	
    	switch (menu_principal){
    		case 1: 
    		system("cls");
    		spaceodessey_main();
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		system("color 07");
    		break;
    		
    		case 2: 
    		system("cls");
    		trivia_main();
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		system("color 07");
    		break;
    		
    		case 3: 
    		system("cls");
    		headlead_main();
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		system("color 07");
    		break;
    		
    		case 4: 
    		MostrarCursor();
    		system("cls");
    		paintpp_main();
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		system("color 07");
    		break;
    		
    		case 5: 
    		system("cls");
    		dados_main();
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		system("color 07");
    		break;
    		
    		case 6:
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		consulta=true;

    		
    		
    		
    		while(consulta){
    			SetConsoleOutputCP(437);
    			pintar_limites();
    			SetConsoleOutputCP(65001);
    			gotoxy(5,5); cout<<"¿Qué juego desea consultar?";
    			gotoxy(5,6);cout<<"1- Space Odessey";
    			gotoxy(5,7);cout<<"2- Trivia";
    			gotoxy(5,8);cout<<"3- Head and Lead";
    			gotoxy(5,9);cout<<"4- Paint++";
    			gotoxy(5,10);cout<<"5- Dados";
    			gotoxy(5,11);cout<<"6- Salir";
    			gotoxy(5,12); cin>>seleccion_consulta;
    			system("cls");
    			
    			if(seleccion_consulta==1){
    				SetConsoleOutputCP(437);
    				pintar_limites();
    				SetConsoleOutputCP(65001);
    				gotoxy(5,5); cout<<"SPACE ODESSEY"<<endl;
    				gotoxy(5,6); cout<<"* El juego consiste en esquivar los asteroides al mismo tiempo que les disparas para acumular puntos"<<endl;
    				gotoxy(5,7);cout<<"* Cuenta con cuatro modos de juego (con diferentes espcificaciones), que puedes elegir al iniciar el juego";
    				gotoxy(5,8); cout<<"CONTROLES";
    				gotoxy(5,9);cout<<"j -> Movimiento de la nave hacia la izquierda";
    				gotoxy(5,10);cout<<"l -> Movimiento de la nave hacia la derecha";
    				gotoxy(5,11);cout<<"i -> Movimiento de la nave hacia arriba";
    				gotoxy(5,12);cout<<"k -> Movimiento de la nave hacia  abajo";
    				gotoxy(5,14);cout<<"a -> Disparo de la nave";
    				gotoxy(5,16);cout<<"p -> Pausa (no sirve para continuar, será necesario utilizar otra tecla)";
    				gotoxy(5,17);cout<<"ES NECESARIO MANTENER LAS TECLAS EN minusculas" ;
    				gotoxy(5,19);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
				}
				
				else if(seleccion_consulta==2){
    				SetConsoleOutputCP(437);
    				pintar_limites();
    				SetConsoleOutputCP(65001);
    				gotoxy(5,5); cout<<"TRIVIA";
    				gotoxy(5,6); cout<<"* El juego consiste en una serie de preguntas del tema que elija el usuario en el menú principal";
    				gotoxy(5,7);cout<<"* De acuerdo a las preguntas respondidas correctamente se le asignará un puntaje";
    				gotoxy(5,8);cout<<"* Puede alternar las configuraciones para utilizar diferentes colores de fondo y letra o cambiar el idioma";
    				gotoxy(5,9);cout<<"* Para seleccionar la respuesta escriba la letra del inciso que usted considere correcto";
    				gotoxy(5,11);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
    				
				}
				
				else if(seleccion_consulta==3){
    				SetConsoleOutputCP(437);
    				pintar_limites();
    				SetConsoleOutputCP(65001);
    				gotoxy(5,5); cout<<"HEAD AND LEAD";
    				gotoxy(5,6); cout<<"* El juego consiste en una historia de elección, a lo largo de esta nos adentraremos en";
    				gotoxy(5,7);cout<<"la segunda guerra mundial, en los pies de un soldado con amnesia";
    				gotoxy(5,9);cout<<"* Para jugar eligiremos un nombre y a lo largo de la historia se nos presentaran decisiones";
    				gotoxy(5,10);cout<<"que podemos tomar, escribiendo en el teclado el número de la respuesta que consideremos correcta";
    				gotoxy(5,12);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
				}
				
				else if(seleccion_consulta==4){
					SetConsoleOutputCP(437);
    				pintar_limites();
    				SetConsoleOutputCP(65001);
					gotoxy(5,5); cout<<"PAINT++";
    				gotoxy(5,6); cout<<"* El juego consiste en un lienzo en blanco donde puede pintar lo que quiera";
    				gotoxy(5,7); cout<<"* Puede alternar entre modo brillante y oscuro según sea su gusto";
    				gotoxy(5,9); cout<<"CONTROLES";
    				gotoxy(5,10);cout<<"j -> Pintar a la izquierda";
    				gotoxy(5,11);cout<<"l -> Pintar a la derecha";
    				gotoxy(5,12);cout<<"i -> Pintar hacia arriba";
    				gotoxy(5,13);cout<<"k -> Pintar hacia  abajo";
    				gotoxy(5,15);cout<<"m -> Salir al menú principal";
    				gotoxy(5,16);cout<<"n -> Limpiar pantalla";
    				gotoxy(5,17);cout<<"ES NECESARIO MANTENER LAS TECLAS EN minusculas" ;
    				gotoxy(5,19);cout<<"COLORES Y PINCELES";
    				gotoxy(5,21);cout<<"* Con los números del 0 al 9 puede alternar entre los colores que se muestran debajo del lienzo" ;
    				gotoxy(5,22);cout<<"* Con los teclas E, R, T, Y ´puede alternar entre los pinceles que se muestran sobre el lienzo" ;
    				gotoxy(5,23);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
				}
				
				else if(seleccion_consulta==5){
    				SetConsoleOutputCP(437);
    				pintar_limites();
    				SetConsoleOutputCP(65001);
    				gotoxy(5,5); cout<<"DADOS";
    				gotoxy(5,6); cout<<"* El juego consiste en dos dados que el usuario puede tirar para obtener dos números aleatorios";
    				gotoxy(5,8);cout<<"CONTROLES";
    				gotoxy(5,10);cout<<"t -> Tirar dados";
    				gotoxy(5,11);cout<<"s -> Salir";
    				gotoxy(5,13);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
    				
				}
				else {
					consulta=false;
				}
			}
			SetConsoleOutputCP(437);
    		pintar_limites();
    		break;
    		
    		case 7:
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
			SetConsoleOutputCP(65001);
			gotoxy(5,5); cout<<"AYUDA";
			gotoxy(5,6); cout<<"STRESS RAVINE";
    		gotoxy(5,8); cout<<"Stress Ravine es un menú de juegos para evitar el estrés. Consta de 5 juegos: dados, naves, pintura y trivia";
    		gotoxy(5,9);cout<< "CREADORES: ";
    		gotoxy(5,10);cout<< "Carlos Gael Hernández Parrilla ";
    		gotoxy(5,11);cout<< "Emmanuel Hernández de Jesús ";
    		gotoxy(5,12);cout<< "Said Alcántara Pacheco ";
    		gotoxy(5,13);cout<< "José Francisco Gregorio Hernández ";
    		gotoxy(5,15);cout<<"CONTACTO";
    		gotoxy(5,16);cout<< "TEL:5510097293 ";
    		gotoxy(5,17);cout<< "MAIL:gotyoftheyeardelanio@gmail.com ";
    		gotoxy(5,18);cout<< "SITE: https://sites.google.com/soycecytem.mx/juegosdidacticosabpcefs/página-principal ";
    		gotoxy(5,20);cout<<"Presione cualquier tecla para regresar al menú";
    				getch();
    				system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
			SetConsoleOutputCP(65001);
			break;
			
			case 8: 
    		system("cls");
			stress_ravine=false;
			break;
			
			default: 
			system("cls");
			SetConsoleOutputCP(437);
    		pintar_limites();
    		SetConsoleOutputCP(65001);
    		gotoxy(5,5); cout<<"SELECCIONE UNA OPCIÓN VÁLIDA"<<endl;
    		Sleep(500);
    		system("cls");
    		SetConsoleOutputCP(437);
    		pintar_limites();
    		SetConsoleOutputCP(65001);
    		break;
    		
		}
		
    	
    	
    	
    	
    	
    	Sleep(30);
	}  
	
	system("color");
	
		
	return 0;
}