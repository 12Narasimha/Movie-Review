#include <stdio.h>
#include <stdlib.h>
#define MAX_MOVIES 5
#define MAX_REVIEW_LENGTH 200
typedef struct {
    char movieName[50];
    char review[MAX_REVIEW_LENGTH];
} Movie;
void displayMovies(Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s\nReview: %s\n\n", i + 1, movies[i].movieName, movies[i].review);
    }
}
void addMovieReview(Movie movies[], int *count) {
    if (*count < MAX_MOVIES) {
        getchar();
        printf("Enter movie name: ");
        fgets(movies[*count].movieName, 50, stdin);
        printf("Enter review: ");
        fgets(movies[*count].review, MAX_REVIEW_LENGTH, stdin);
        (*count)++;
        printf("Review added!\n");
    } else {
        printf("Movie limit reached.\n");
    }
}
int main() {
    Movie movies[MAX_MOVIES];
    int count = 0, choice;
    while (1) {
        printf("\n1. View Movies\n2. Add Review\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (count == 0) printf("No movies yet.\n");
            else displayMovies(movies, count);
        } else if (choice == 2) {
            addMovieReview(movies, &count);
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
