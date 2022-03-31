// slow version, check slop with float
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x1 = coordinates[0][0];
    int x2 = coordinates[1][0];
    int y1 = coordinates[0][1];
    int y2 = coordinates[1][1];
    float slop = (float)(x2 - x1) / (y2 - y1);

    if (y2 - y1 == 0) {
        // vertical line
        for (int i = 2; i < coordinatesSize; i++) {
            if (coordinates[i][1] != y1) return false;
        }
        return true;
    } else {
        for (int i = 2; i < coordinatesSize; i++) {
            float x = (float)(coordinates[i][0] - coordinates[i - 1][0]) / (coordinates[i][1] - coordinates[i - 1][1]);
            if (x != slop) return false;
        }
        return true;
    }
}

// faster version, check slop with integer
// Runtime: 16 ms, faster than 27.45% of C online submissions for Check If It Is a Straight Line.
// Memory Usage: 6.4 MB, less than 88.24% of C online submissions for Check If It Is a Straight Line.
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x1 = coordinates[0][0];
    int x2 = coordinates[1][0];
    int y1 = coordinates[0][1];
    int y2 = coordinates[1][1];
    int a1 = (x2 - x1);
    int b1 = (y2 - y1);

    if (y2 - y1 == 0) {
        // vertical line
        for (int i = 2; i < coordinatesSize; i++) {
            if (coordinates[i][1] != y1) return false;
        }
        return true;
    } else {
        for (int i = 2; i < coordinatesSize; i++) {
            int a2 = (coordinates[i][0] - coordinates[i - 1][0]);
            int b2 = (coordinates[i][1] - coordinates[i - 1][1]);
            if (a1 * b2 != a2 * b1) return false;
        }
        return true;
    }
}
// check slop with integer + code optimization
// Runtime: 11 ms, faster than 55.88% of C online submissions for Check If It Is a Straight Line.
// Memory Usage: 6.5 MB, less than 52.94% of C online submissions for Check If It Is a Straight Line.
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int x1 = coordinates[0][0];
    int x2 = coordinates[1][0];
    int y1 = coordinates[0][1];
    int y2 = coordinates[1][1];
    int a1 = (x2 - x1);
    int b1 = (y2 - y1);
    int a2;
    int b2;

    if (y2 - y1 == 0) {
        // vertical line
        for (int i = 2; i < coordinatesSize; i++) {
            if (coordinates[i][1] != y1) return false;
        }
        return true;
    } else {
        for (int i = 2; i < coordinatesSize; i++) {
            a2 = (coordinates[i][0] - x1);
            b2 = (coordinates[i][1] - y1);
            if (a1 * b2 != a2 * b1) return false;
        }
        return true;
    }
}
