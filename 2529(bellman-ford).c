#include <stdio.h>

const int Infinity = 1 << 30;

struct edge {
    int start;
    int end;
    int weight;
} Edge[20000];

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    int totalNode;
    int totalAdj;
    int dist[1001];  //��¼ĳ�ڵ㵽���Ϊ1��������̾���
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //��������ͼ
        for (int i = 0; i < totalAdj; i++) {
            scanf("%d %d %d", &Edge[i].start, &Edge[i].end, &Edge[i].weight);
        }
        //��ʼ��dist����
        dist[1] = 0;
        for (int i = 2; i <= totalNode; i++) {
            dist[i] = Infinity;
        }
        int ans = 0;
        int cnt = 0;  //��¼dist���鱻���µ��ܴ���
        int temp = Infinity;
        while (1) {
            cnt++;
            //������������ͼ�ıߣ�����dist���飬����ν�ġ��Ա߽��з��ɲ�����
            //������Ҫע�⣬�����Ŀ�ж�ͨ�������о������Ƶģ�����ֱ�Ӷ�dist������д�������
            //��Ҫʹ��bellman-ford�㷨��ԭʼ��̬�滮�汾�����������������Ͽ������ѭ������
            //����ο���https://blog.csdn.net/crabstew/article/details/89159942
            for (int j = 0; j < totalAdj; j++) {
                struct edge cur = Edge[j];
                dist[cur.end] = min(dist[cur.end], dist[cur.start] + cur.weight);
            }
            /*
                �����б����һ�η��ɲ����󣬿��ܳ������µļ��������
                һ��dist[totalNode] < 0�������������˳�ѭ��
                ����dist[totalNode] >= 0����cnt < n - 1��������������ѭ��
                ����dist[totalNode] = Infinity����cnt = n - 1��������϶��޽⣬�˳�ѭ��
                �ġ�0 <= dist[totalNode] < Infinity����cnt >= n - 1
                    ��ʱ��Ҫ���ͼ���Ƿ���ڻ�Ӱ��distֵ�ĸ�Ȩ�����֡�
                    �����������temp���뵱ǰ��distֵ���ٹ۲��ں������ɲ�������ֵ�Ƿ���һ����С��
                    �����С����˵��distֵ�յ���Ȩ��Ӱ�죬����һ���н⣬��֮������һ���޽⡣
            */
            if (dist[totalNode] < 0 || dist[totalNode] < temp && cnt > totalNode - 1) {
                ans = 1;
                break;
            }
            else if (dist[totalNode] >= temp && cnt >= totalNode - 1) {
                ans = 0;
                break;
            }
            else if (cnt >= totalNode - 1) {
                temp = dist[totalNode];
            }
        }
        //�����
        printf(ans ? "YES\n" : "NO\n");
    }
}