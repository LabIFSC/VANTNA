class Motor
{
    public:
    int velocidade;
    char sentido;
    int p1;
    int p2;
    int enable;

    public:
    Motor(int p1, int p2, int e);
    void setup();
    void gira_horario(int vel);
    void gira_antihorario(int vel);
    void freia ();
};