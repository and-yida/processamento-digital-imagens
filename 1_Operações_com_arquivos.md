# OPERAÇÕES COM ARQUIVOS (C++)

<br />

## ofstream

Classe para arquivo de saída: ofstream  
Incluir biblioteca fstream: `#include <fstream>`

Declaração
```c++
ofstream arquivo;
    arquivo.open("nome.txt");
```

Exemplo de função - salvando uma imagem que é uma matriz de valores que correspondem aos pixels:
```c++
    void saveFile(image &img, const string &name) {
        ofstream file(name.c_str(), ios::out);                                 //ios::out abre arquivo para operação de saída
        if (file.fail()) {
            cout << "Erro ao abrir o arquivo " << name << endl;
            return;
        }
        //as três primeiras linhas são cabeçalho para: tipo de imagem, largura, altura e range do tom do pixel
        file << img.type << endl
             << img.w << ' ' << img.h << endl
             << img.bits << endl;
        //escrevendo os valores da matriz
        for (int i = 0; i < img.w; i++) {
            for (int j = 0; j < img.h; j++) {
                file << +img.data[i][j] << endl;
            }
        }
        file.close();
    }
```

No main:
```c++
    saveFile(img, "imagem.pgm");
```

<br />

## ifstream

Classe para arquivo de entrada: ifstream  

Declaração
```c++
    ifstream arquivo;
    string linha;                                           //precisamos de uma variável para armazenar a linha lida
    arquivo.open("nome.txt");
    if(aquivo.is_open()) {                                  //podemos testar se o arquivo foi aberto e executar a leitura ou
    //if(aquivo.fail()) {}                                  //testar primeiro se deu erro na abertura do arquivo
        while(getline(arquivo, linha)) {                    //getline retorna a linha lida para o parâmetro fornecido; isto é, será armazenada na variável 'linha'
            cout << linha << endl;                          //imprimindo linha por linha
        }
        arquivo.close();
    }
```

Exemplo de função - lendo uma imagem:
```c++
    void loadFile(image &img, const string &name) {
        ifstream file(name.c_str(), ios::in);
        if (file.fail()) {
            cout << "Erro ao abrir o arquivo " << name << endl;
            return;
        }
        //primeiro retiramos informações do cabeçalho referente à imagem, que aparecem nas 3 primeiras linhas
        eatComment(f);
        file >> img.type;
        eatComment(f);
        file >> img.w;
        eatComment(f);
        file >> img.h;
        eatComment(f);
        file >> img.bits;
        //lendo os valores da matriz
        img.data.resize(img.w, vector<uint8_t>(img.h));
        for (int i = 0; i < img.w; i++) {
            for (int j = 0; j < img.h; j++) {
                int v;
                f >> v;
                img.data[i][j] = v;
            }
        }
        file.close();
    }
```

<br />

## fstream

Classe para arquivo tanto de entrada como de saída: fstream  

Declaração
```c++
    fstream arquivo;
```

Exemplo - gravar nomes digitados pelo usuário:
```c++
    fstream arquivo;
    char opc='s';
    string nome, linha;

    arquivo.open("nome.txt", ios::out|ios::app);            //app determina que novas entradas sejam adicionadas ao arquivo, de forma que não sobrescrevam conteúdos anteriores

    while((opc == 's')or(opc == 'S')){
        cout << "Digite um nome: ";
        cin >> nome;
        arquivo << nome << endl;
        cout << endl << "Digitar um novo nome? [s/n] ";
        cin >> opc;
        system ("CLS");                                     //comando do Windows de saída
    }
    arquivo.close();

    arquivo.open("nome.txt", ios::in);

    cout << "Nomes digitados: " << endl;

    if(arquivo.is_open()) {
        while(getline(aqruivo, linha)){
            cout << linha << endl;
        }
        arquivo.close();
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
```

<br />
