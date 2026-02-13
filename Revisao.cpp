/*1. Elabore um programa em C/C++ que calcule e imprima o salário de 50
funcionários. Sabe-se que
• para cada funcionário deve ser informado o salário base,
• que ele tem 16% de gratificação e paga 30% de imposto.
Ao final do algoritmo deve ser impresso o valor pago aos 50 funcionários e o
total de imposto que foi descontado destes funcionários.*/
#include <iostream>
using namespace std;
float v[50];
float t[50];

int main(){
    float gratif = v[0], impos = v[0];
    for(int i=1; i<50; i++){
        cout<<"Digite o Salario Base : "<<endl;
        cin>>v[i];
        gratif = v[i] + 0.16;
        impos = v[i] - 0.30;
        t[i] = gratif - impos;
        cout<<"Salario Base: "<<v[i]<<endl;
        cout<<"Valor pago para o funcionario "<<i<<" : "<<v[i] + t[i]<<endl;
        cout<<"Imposto descontado do funcionario: "<<t[i]<<endl;
        i++;
    }
}

/*2. Elabore um programa em C/C++ que receba a idade de M pessoas, calcule e
imprima a média de idade deste grupo.*/ 

#include <iostream>
using namespace std;
int M;
int Id;
int somaid = 0;

int main(){
    cout<<"Digite a quantidade de Pessoas: "<<endl;
    cin>>M;
    for(int i=0; i<M; i++){
        cout<<"Digite a Idade da "<<i+1<<" Pessoa: "<<endl;
        cin>>Id;
        somaid = somaid + Id;
    }
    cout<<"Media de Idade: "<<somaid/M<<endl;

}

/*3. Faça um programa em C/C++ que calcule e imprima a seguinte soma: 3/99 -3 2/98 + 3 3/97 - . . .399/1*/
#include <iostream>
#include <cmath>
using namespace std;

void soma(){
    float conta = 0, soma = 0;
    int denominador = 99, porcentagem = 1;
    for(int i=porcentagem; i<=99; i++){
        soma = pow(3, porcentagem) / denominador;
        if(i % 2 == 0){
            conta -= soma;
        } 
        else {
            conta += soma;
        }
    denominador--;
    }
    cout<<"Calculo Final: "<<conta<<endl;
}

int main(){
    soma();
}

/*4. Faça um programa em C/C++ para calcular a área de um triângulo retângulo. Esse
programa não pode permitir a entrada de dados inválidos, ou seja, medidas
menores ou iguais a 0.*/ 

#include <iostream>
using namespace std;
float a, b;

int main(){
cout<<"Digite a Base: "<<endl;
cin>>b;
cout<<"Digite a Altura: "<<endl;
cin>>a;
if(b<=0 && a<=0){
    cout<<"Numero invalido Digitado!"<<endl;
} 
  else {
    cout<<"Area do Triangulo Retangulo: "<<(b * a)/2<<endl;
}
}

/*5. Faça um programa em C/C++ que receba uma seqüência de números finalizada
pelo número 0, calcule e imprima:
• a média dos números menores que 300.
• o percentual de números maiores que 100;
• a média dos números pares;
• a soma dos números ímpares;*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int contMenor300 = 0, contMaior100 = 0;
    int contPares = 0, contTotal = 0;
    int somaMenor300 = 0, somaPares = 0, somaImpares = 0;

    cout<<"Digite numeros com 0 para finalizar: "<<endl;
    cin>>n;

    while (n != 0) {
        contTotal++;

        if (n < 300) {
            somaMenor300 += n;
            contMenor300++;
        }

        if (n > 100) {
            contMaior100++;
        }

        if (n % 2 == 0) {
            somaPares += n;
            contPares++;
        } else {
            somaImpares += n;
        }

        cin>>n;
    }

    if (contMenor300 > 0)
        cout<<"Media dos numeros menores que 300: "<<somaMenor300/contMenor300<<endl;

    if (contTotal > 0)
        cout<<"Percentual dos numeros maiores que 100: "<<(contMaior100 * 100)/contTotal<<"%"<<endl;

    if (contPares > 0)
        cout<<"Media dos numeros pares: "<<somaPares/contPares<<endl;

    cout<<"Soma dos numeros impares: "<<somaImpares<<endl;

    return 0;
}


/*6. Faça um programa em C/C++ que leia o NOME do Morador e a QUANTIDADE
de consumo de água gasto por 5 apartamentos durante um mês. Armazene os
dados em dois vetores (vNome e vCons). Depois da leitura, o algoritmo deve:
- imprimir o nome dos moradores que consumiram mais de 30 mts cúbicos;
- calcular a média de consumo dos moradores que consumiram menos de 100 mts
cúbicos mensais;
- classificar os valores em ordem decrescente de consumo.*/ 
#include <iostream>
#define T 2
using namespace std;

struct conta{
    string vNome;
    float vCons;
};

conta v[T];

void consumo(){
    int c = 0;
    float md = 0;
    conta aux;
    cout<<"Consumiu mais de 30 mts "<<endl;
    for(int i=0; i<T; i++){
        if(v[i].vCons>30){
            cout<<" - "<<v[i].vNome<<endl;
        }
        if(v[i].vCons<100){
            md += v[i].vCons;
            c++;  
        }
    }
    for (int i = 0; i < T - 1; i++) {
        for (int j = i + 1; j < T; j++) {
            if (v[i].vCons < v[j].vCons) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    cout << "\nConsumo em ordem decrescente:\n";
    for (int i = 0; i < T; i++) {
        cout << v[i].vNome << " - " << v[i].vCons << " m³\n";
    }
    if(c != 0){
    cout<<"Média de consumo dos moradores que consumiram menos de 100 mts: "<<md/c<<endl;
    } else { cout<<"Nao teve morador que consumiu menos que 100 mts: "<<endl;
}
}

int main(){
    for(int i=0; i<T; i++){
        cout<<"Digite o "<<i+1<<" Nome: ";
        cin>> v[i].vNome;
        cout<<"Digite o "<<i+1<<" Consumo de Agua: ";
        cin>> v[i].vCons;
    }
    consumo();
    return 0;
}


/*7. Elabore um algoritmos que verifique e mostre os números entre 1000 e 2000
(inclusive) que, quando divididos por 11, produzam resto igual a 5.*/ 
#include <iostream>
using namespace std;

void numeros() {
    int a = 1000;
    while (a <= 2000) {
        if (a % 11 == 5) {
            cout << "Numero dividido por 11 com resto 5: " << a << endl;
        }
        cout<<"Numero entre 1000 e 2000: "<<a<<endl;
        a++;
    }
}

int main() {
    numeros();
    return 0;
}
/*8. Elabore um programa em C/C++ para ler uma matriz VALOR 4x4, calcule e
imprima:
• A soma dos valores ímpares armazenados na matriz;
• A quantidade de elementos com menor que 100;
• A média dos valores pares maiores que 30 armazenados na matriz;
• A soma dos valores das colunas (guarde a soma em um vetor)
• A média dos valores das linhas ((guarde o resultado em um vetor)
• O maior e o menor valor armazenado.*/
#include <iostream>
using namespace std;

int main() {
    double v[4][4];

    double somaImpar = 0;
    int qtdMenor100 = 0;

    double somaParMaior30 = 0;
    int contParMaior30 = 0;

    double somaColuna = 0;
    double mediaLinha = 0;

    double maior = V[0][0], menor = V[0][0];

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout<<"\nDigite o valor "<<i+1<<","<<j+1<< ": "<<endl;
            cin>>v[i][j];
            }
        }
    for(int i=0; i<4; i++) {
        double somaLinha = 0;

        for(int j=0; j<4; j++) {
            int valorInt = (int)v[i][j];
            if(valorInt % 2 != 0) {
                somaImpar += v[i][j];
            }
            if(v[i][j] < 100) {
                qtdMenor100++;
            }
            if(valorInt % 2 == 0 && v[i][j] > 30) {
                somaParMaior30 += v[i][j];
                contParMaior30++;
            }
            somaColuna[j] += v[i][j];
            somaLinha += v[i][j];
            if(v[i][j] > maior){
                maior = v[i][j];
            }else if(v[i][j] < menor){
                menor = v[i][j];
        }
        mediaLinha[i] = somaLinha / 4;
    }
    cout<<"\nSoma dos valores ímpares: "<<somaImpar<<endl;
    cout<<"\nQuantidade de elementos menores que 100: "<<qtdMenor100<<endl;

    if(contParMaior30 > 0){
        cout<<"Média dos valores pares maiores que 30: "<<somaParMaior30/contParMaior30<<endl;
    }else{
        cout<<"Não há valores pares maiores que 30.\n"<<endl;
    }
    cout<<"\nSoma das colunas:\n"<<endl;
    for(int j = 0; j < 4; j++){
        cout<<"Coluna " << j + 1 << ": "<<somaColuna[j]<<endl;
    }
    cout<<"\nMédia das linhas:\n"<<endl;
    for (int i = 0; i < 4; i++) {
        cout<<"Linha " << i + 1 << ": "<<mediaLinha[i]<<endl;
    }
    cout<<"\nMaior valor: "<<maior<<endl;
    cout<<"\nMenor valor: "<<menor<<endl;
    }
}
/*9. Faça um algoritmo que receba uma sequencia de números finalizada pelo número
0, calcule e imprima:
a. a soma dos números pares;
b. a média dos números ímpares;
c. o percentual de números menores que 300;
d. a média dos números maiores que 25.*/
#include <iostream>
using namespace std;

int main() {
    int n;
    int contTotal = 0;
    int somaPares = 0;
    int somaImpares = 0, contImpares = 0;
    int contMenor300 = 0;
    int somaMaior25 = 0, contMaior25 = 0;

    cout<<"Digite numeros (0 para finalizar): "<<endl;
    cin>>n;

    while(n != 0){
        contTotal++;
        if(n % 2 == 0){
            somaPares += n;
        }
        if(n % 2 != 0){
            somaImpares += n;
            contImpares++;
        }
        if(n < 300){
            contMenor300++;
        }
        if(n > 25){
            somaMaior25 += n;
            contMaior25++;
        }
        cin>>n;
    }
    cout<<"Soma dos numeros pares: "<<somaPares<<endl;
    if (contImpares > 0)
        cout<<"Media dos numeros impares: "<<somaImpares/contImpares<<endl;
    else{
        cout<<"Nao houve numeros impares."<<endl;
    }
    if(contTotal > 0){
        cout<<"Percentual de numeros menores que 300: "<<(contMenor300 * 100)/contTotal<<"%"<<endl;
    }    
    if(contMaior25 > 0){
        cout<<"Media dos numeros maiores que 25: "<<somaMaior25/contMaior25<<endl;
    }    
    else{
        cout<<"Nao houve numeros maiores que 25. "<<endl;
    }    
}

/*10. Faça um programa que leia uma lista de 40 números inteiros, não repetidos, e
armazene-o em um vetor. A seguir, o programa deve ler uma lista de números
terminada pelo número 0 (que não entrará nos cálculos). Para cada número da
lista, o programa deve verificar se ele está no vetor. Ao final do programa, deve
ser mostrado o número de vezes que cada número do vetor foi encontrado.*/
#include <iostream>
using namespace std;

int main(){
    int v[40];
    int cont = 0; 
    int n;
    bool repetido;
    cout << "Digite 40 numeros inteiros (nao repetidos): "<<endl;
    for (int i=0; i<40; i++) {
        do{
            repetido = false;
            cin>>v[i];
            for (int j=0; j<i; j++){
                if (v[i] == v[j]){
                    repetido = true;
                    cout<<"Numero repetido! Digite outro: "<<endl;
                }
            }
        } while (repetido);
    }
    cout<<"Digite numeros para pesquisa (0 para finalizar): "<<endl;
    cin>>n;
    while(n != 0){
        for (int i=0; i<40; i++){
            if (n == v[i]){
                cont++;
            }
        }
        cin>>n;
    }
    cout<<"Quantidade de vezes que cada numero foi encontrado: "<<endl;
    for(int i=0; i<40; i++) {
        cout << "Numero "<<v[i]<<": "<<cont<< "vez(es)";
    }
}
/*11. Elabore um algoritmo que leia uma matriz P 5x5 e informe se a mesma é
simétrica ou não.
OBS: Para uma matriz ser simétrica os elementos A[I,J] = A[J,I].*/
#include <iostream>
#define T 5
using namespace std;

int P[T][T];

int main(){
    int i, j;
    for( i=0; i<T; i++){
        for( j=0; j<T; j++){
        cout<<"Digite o valor "<<i+1<<" , "<<j+1<<endl;
        cin>>P[i][j];
        }
    }
    if(P[i][j] == P[j][i]){
        cout<<"Matriz Simetrica"<<endl;
    } else {
        cout<<"Matriz Assimetrica"<<endl;
    }
}
/*12. Elabore um algoritmo que leia uma matriz D 5x5 quadrada e calcule a média dos
valores armazenados na diagonal principal e a soma dos valores armazenados na
diagonal secundária.*/
#include <iostream>
#include <conio.h>
#define T 5
using namespace std;
int a[T][T];
int main(){
    int c1 = 0, c2 = 0, md1 = 0, md2 = 0;
    int i, j;
    for( i=0; i<T; i++){
        for( j=0; j<T; j++){
            cout<<" Digite o "<<i+1<<","<<j+1<< " elemento:\n";
            cin>>a[i][j];
        }
    } 
    cout<<"Media dos elementos da diagonl principal:" <<endl;
    for( i=0; i<T; i++){
        for( j=0; j<T; j++){
            if(i==j){
                md1 += a[i][j];
                c1++;
            }
        }
    }
    cout<<"  "<<md1/c1<<endl;
    cout<<"Media dos elementos da diagonal secundaria:" <<endl;
    for( i=0; i<T; i++){
        for( j=0; j<T; j++){
            if(i+j==T-1){
                md2 += a[i][j];
                c2++;
            }
        }
    }
    cout<<"  "<<md2/c2<<endl;
    getch();
}

/*13.Para atingir-se o índice olímpico, são realizados vários torneios de corridas de 100
metros. Leia o nome e o tempo de um atleta e apresente sua pontuação, segundo a
tabela abaixo:
T < 10 seg → 100 ptos
T >= 10 e T <=13 seg → 70 ptos
 T > 13 Seg → 40 ptos*/
#include <iostream>
#define T 1
using namespace std;

struct corrida{
    string vNome;
    float vTempo;
};

corrida v[T];

int main(){
    int i;
    for( i = 0; i<T; i++){
        cout<<"Digite o nome do atleta: "<<endl;
        cin>>v[i].vNome;
        cout<<"Digite o tempo do atleta: "<<endl;
        cin>>v[i].vTempo;
    }
    cout<<" --- Pontuacao do Atleta ---"<<endl;
    for( i=0; i<T; i++){
        if(v[i].vTempo < 10){
            cout<<"100 ptos"<<" - "<<" atleta "<<v[i].vNome;
        } else if(v[i].vTempo >= 10 && v[i].vTempo <= 13){
            cout<<"70 ptos "<<" - "<<" atleta "<<v[i].vNome;
        } else if(v[i].vTempo > 13){
            cout<<"40 ptos "<<" - "<<" atleta "<<v[i].vNome;
        }
    }
}
/*14.Calcular a soma dos 30 primeiros termos das seqüências:
a) 1 – 1/2 + 1/4 – 1/6 + 1/8 . . .
b) 63 + 61 + 59 / 2 + 57 / 3 + . . .
c) 480/10 – 475 / 11 + 470 / 12 ....*/
#include <iostream>
#include <conio.h>
using namespace std;

void A() {
    float soma = 0;
    int denom = 1;

    for (int i = 1; i <= 30; i++) {
        if (i % 2 == 0)
            soma -= 1 / denom;
        else
            soma += 1 / denom;

        denom += 1;
    }

    cout<<"Resultado A: "<<soma<<endl;
}
void B() {
    float soma = 0;
    int num = 63;
    int denom = 1;

    for (int i = 1; i <= 30; i++) {
        if (i <= 2) {
            soma += num;
        } else {
            float soma += num / denom;
            denom++;
        }
        num -= 2;
    }

    cout<<"Resultado B: "<<soma<<endl;
}
void C() {
    float soma = 0;
    int num = 480;
    int denom = 10;

    for (int i = 1; i <= 30; i++) {
        if (i % 2 == 0)
            soma -= (float)num / denom;
        else
            soma += (float)num / denom;

        num -= 5;
        denom++;
    }

    cout<<"Resultado C: "<<soma<<endl;
}

int main(){
    A();
    B();
    C();
    getch();
}
/*15.Leia m e n e calcule a soma de todos os números ímpares entre n e m*/
#include <iostream>
#include <conio.h>
#define M 3
#define N 2
using namespace std;

int m[M], n[N]; 

int main(){
    int i, j, soma = 0;
    int t1, t2, aux;
    for(i=0; i<M; i++){
        cout<<"Digite o "<<i+1<<" M: "<<endl;
        cin>>m[i];
    }
    for(j=0; j<N; j++){
        cout<<"Digite o "<<i+1<<" N: "<<endl;
        cin>>n[i];
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {

             t1 = n[j];
             t2 = m[i];

            if (t1 > t2) {
                aux = t1;
                t1 = t2;
                t2 = aux;
            }
        }
    }
    for (i=t1; i<=t2; i++) {
                if (i % 2 != 0) {
                    soma += i;
                }
    }
    if(soma != 0){
        cout<<"Soma de todos os numeros impares entre N e M: "<<soma<<endl;
    } else {
        cout<<"Nenhum numero impar digitado."<<endl;
    }
    getch();

}
