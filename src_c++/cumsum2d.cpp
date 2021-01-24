//
// Created by chicken1925 on 2021/01/24.
//

class CumulativeSum_2D {
public:
    vec<vec<i64>> data;

    CumulativeSum_2D(i64 h, i64 w) : data(h + 1, vec<i64>(w + 1)) {}

    void add(i64 x, i64 y, i64 z) {
        x++, y++;
        if (y >= data.size() || x >= data[0].size())return;
        data[y][x] += z;
    }

    void build() {
        for (i32 i = 1; i < len(data); i++) {
            for (i32 j = 1; j < len(data[i]); j++) {
                data[i][j] += data[i -1][j] + data[i][j - 1] - data[i - 1][j - 1];
            }
        }
    }

    i64 query(i64 sy, i64 sx, i64 gy, i64 gx) {
        return data[gy][gx] - data[sy][gx] - data[gy][sx] + data[sy][sx];
    }
};
