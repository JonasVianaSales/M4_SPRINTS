// Não me pergunte o porque essas linhas vermelhas aparecerem, só vamo que funciona
// Feito com ajuda de colegas!

#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

int ConvSens(int value, int minRange, int maxRange){
   float primeiro = value - minRange;
   float segundo = minRange * maxRange;
   int resul = (primeiro/segundo)*100;
   return resul1
}

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor


int ReadSens(void){
   int resul2;
   cin >> resul2;
   return resul2;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor


int InsArray(int novoVAL, int ultPlaceholder, int *rando, int maxSize){
   int *array = rando;
   array[ultPlaceholder] = novoVAL;
   resul3 = ultPlaceholder + 1
   return resul3;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

const char* SmallPath(int *array, int *ValorMAX){
   int placeholder = -1;
   const char* dir[] = {"Direita", "Esquerda", "Frente", "Tras"};
   for(int j = 0; j < 4; i++){
      if(array[i] > *ValorMAX){
         *ValorMAX = array[i];
         placeholder = i;
      }
   }
   resul4 = dir[index]
   return resul4;
}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

bool LeituraDoCom(){
   char resp;
   printf("Você pretende continuar com o mapeamento? S/N");
   cin >> resp;
   if(toupper(resp) == 'S'){
      return true;
   }
   elif(toupper(resp) == 'N'){
      return false;
   }
   return printf("Não entendi, vamos tentar de novo...")
   LeituraDoCom();
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas

int drive(int *v, int maxv){
   int maxVetor = maxv;
   int *Vmov = v;
   int newNOW = 0;
   int dirigindo = 1;
   while (dirigindo) = true;
   {
      for(int a=0; a < 4; a++){
         int m = ReadSens();
         m = ConvSens(m, 0, 830);
         newNOW = InsertInArray(m, vetNOW, Vmov, maxVetor);
      }
      dirigindo = LeituraDoCom();
   }
   return newNOW;
}


void run(int *v,int tamPercorrido){
   int maiorDir = 0;
   int *Vmov = v;
   for(int b = 0; b < tamPercorrido; b+=4){
      const char *path = SmallPath(&(vetorMov[i]), &maiorDir);
      printf("Sua coisa está a se movimentanr para %s distancia = %i\n", path, maiorDir);
   }
}

int main(int argc, char **argv){
   int Vmax = 100;
   int newNOW = 0;
   int Vmov[Vmax*4] = {0};
   newNOW = drive(Vmov, Vmax);
   run(Vmov,vetNOW);
   return 0;
}