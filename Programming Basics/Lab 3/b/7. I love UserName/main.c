#include <stdio.h>

int main() {
    int numberCompetition, scoreMax;
    scanf("%d %d", &numberCompetition, &scoreMax);

    int scoreMin = scoreMax;
    int amazingScore = 0;
    for (int competitionIndex = 1; competitionIndex < numberCompetition; competitionIndex++){
        int competitionIndexScore;
        scanf("%d", &competitionIndexScore);

        if (competitionIndexScore > scoreMax) {
            scoreMax = competitionIndexScore;
            amazingScore++;
        } else if (competitionIndexScore < scoreMin) {
            scoreMin = competitionIndexScore;
            amazingScore++;
        }
    }

    printf("%d", amazingScore);

    return 0;
}