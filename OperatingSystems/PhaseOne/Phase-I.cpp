#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

char IR[4], R[4];
char M[100][4];
char buffer[41];
int IC, SI, C, L = 0;

FILE *f1, *f2;

void execute(void);

void init() {
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 4; j++)
      M[i][j] = '$';

  for (int i = 0; i < 4; i++)
    IR[i] = R[i] = '$';
}

void clear() {
  for (int i = 0; i < 41; i++)
    buffer[i] = '\0';
}

void Read() {
  if (fgets(buffer, 41, f1) != NULL) {
    int k = 0;
    for (int i = L; i < L + 10; i++) {
      cout << "\n M[" << i << "] : ";
      for (int j = 0; j < 4 && buffer[k] != '\0'; j++) {
        M[i][j] = buffer[k++];
        cout << M[i][j];
      }
    }
  }
  execute();
}

void Write() {
  int k = 0;
  IR[3] = '0';
  clear();
  for (int i = L; i < L + 10; i++) {
    for (int j = 0; j < 4 && M[i][j] != '$'; j++) {
      if (M[i][j] == '\n')
        buffer[k] = ' ';
      else
        buffer[k] = M[i][j];
      cout << buffer[k++];
    }
  }
  buffer[k] = '\n';
  fputs(buffer, f2);
  execute();
}

void Terminate() {
  memset(buffer, 0, 41);
  buffer[0] = '\n';
  buffer[1] = '\n';
  fputs(buffer, f2);
}

void MOS() {
  switch (SI) {
    case 1: Read();
            break;
    case 2: Write();
            break;
    case 3: Terminate();
            break;
    default: SI = 0;
  }
}

void execute() {
  for (int i = 0; i < 4; i++)
    IR[i] = M[IC][i];
  L = ((int)IR[2] - 48) * 10 + ((int)IR[3] - 48);
  IC++;
  
  if (IR[0] == 'G' && IR[1] == 'D') {
    SI = 1;
    cout << "\n In GD";
    MOS();
  }
  else if (IR[0] == 'P' && IR[1] == 'D') {
    SI = 2;
    cout << "\n In PD";
    MOS();
  }
  else if (IR[0] == 'H') {
    SI = 3;
    cout << "\n Program Halted";
    MOS();
  }
  else if (IR[0] == 'L' && IR[1] == 'R') {
    cout << "\n In LR";
    for (int i = 0; i < 4; i++) {
      R[i] = M[L][i];
      cout << "\n\t Data transfered from Memory to Register : " << R[i];
    }
    execute();
  }
  else if (IR[0] == 'S' && IR[1] == 'R') {
    cout << "\n In SR";
    for (int i = 0; i < 4; i++) {
      M[L][i] = R[i];
      cout << "\n\t Data transfered from Register to Memory : " << M[L][i];
    }
    execute();
  }
  else if (IR[0] == 'C' && IR[1] == 'R') {
    for (int i = 0; i < 4; i++) {
      if (R[i] == M[L][i])
        C = 1;
      else {
        C = 0;
        break;
      }
    }
    execute();
  }
  else if (IR[0] == 'B' && IR[1] == 'T') {
    if (C == 1) {
      IC = L;
      cout << "\n\t IC Status : " << IC;
    }
    execute();
  }
  else
    cout << "\n\t Invalid instruction encountered.";
}

int main() {
  int t = 0;
  f1 = fopen("input.txt", "r");
  f2 = fopen("output.txt", "w");
  while (getc(f1) != EOF) {
    system("cls");
    fseek(f1, -1, SEEK_CUR);
    memset(buffer, 0, 45);
    fgets(buffer, 45, f1);

    cout << "\n Buffer contents \n\t";
    for (int i = 0; i < 41; i++)
      cout << buffer[i];
    cout << endl;

    if (buffer[0] == '$' && buffer[1] == 'A' && buffer[2] == 'M' && buffer[3] == 'J') {
      t = 0;
      cout << "\n Program Initiated.";
      init();
    }
    else if (buffer[0] == '$' && buffer[1] == 'D' && buffer[2] == 'T' && buffer[3] == 'A') {
      IC = 0;
      cout << "\n Program is being executed.";
      execute();
    }
    else if (buffer[0] == '$' && buffer[1] == 'E' && buffer[2] == 'N' && buffer[3] == 'D') {
      cout << "\n Program Ended.";
      continue;
    }
    else {
      int k = 0;
      for (int i = t; i < t + 10; i++) {
        cout << "\t M[" << i << "] : ";
        for (int j = 0; j < 4; j++) {
          M[i][j] = buffer[k++];
          cout << M[i][j];
        }
        cout << endl;
      }
      t = t + 10;
    }
  }

  fclose(f1);
  fclose(f2);
}
