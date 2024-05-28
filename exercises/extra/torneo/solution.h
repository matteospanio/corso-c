typedef struct node
{
    int team_id;
    int score;
    int opponent_score;
    struct node *left;
    struct node *right;
} Node;

void print_scores(double *scores);
void get_scores(Node *root, double *scores, double multiplier);
int get_winner(double *scores);
