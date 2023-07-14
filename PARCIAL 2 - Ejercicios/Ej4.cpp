#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct segmento
{
    int L, R;
};
bool compare(segmento a, segmento b) { return a.L < b.L; }
void resolver(int M, vector<segmento> &segmentos)
{ 
    sort(segmentos.begin(), segmentos.end(), compare);
    vector<segmento> solucion;
    int punto = 0;
    int i = 0;
    bool posible = true;
    while (punto < M && i < segmentos.size())
    {
        int maxR = -1;
        int maxI = -1;
        while (i < segmentos.size() && segmentos[i].L <= punto)
        {
            if (segmentos[i].R > maxR)
            {
                maxR = segmentos[i].R;
                maxI = i;
            }
            i++;
        }
        if (maxI == -1)
        {
            posible = false;
            break;
        }

        solucion.push_back(segmentos[maxI]);
        punto = maxR;
    }
    if (posible)
    {
        cout << solucion.size() << endl;
        for (segmento s : solucion)
        {
            cout << s.L << " " << s.R << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M;
        cin >> M;
        vector<segmento> segmentos;

        while (true)
        {
            int L, R;
            cin >> L >> R;
            if (L == 0 && R == 0)
                break;
            segmentos.push_back({L, R});
        }

        resolver(M, segmentos);

        cout << endl;
    }
    return 0;
}