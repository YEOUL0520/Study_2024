import java.util.*;

class Solu {
	// bfs사용, 갔던 곳은 방문처리
    // 상하좌우 좌표
    int[] dx = {0, 1, -1, 0};
    int[] dy = {1, 0, 0, -1};
    
    public int solution(int[][] maps) {
        int answer = 0;

        int[][] visited = new int[maps.length][maps[0].length];

        bfs(maps, visited);

        answer = visited[maps.length - 1][maps[0].length - 1]; // 상대 팀 진영 좌표
        if (answer == 0) { // 상대 팀 진영에 도달X
            answer = -1;
        }
        return answer;
    }
    
    public void bfs(int[][] maps, int[][] visited) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0}); // Queue에 시작 정점 추가
        visited[0][0] = 1;

        while (!q.isEmpty()) { // 더 나아갈수X
            int[] current = q.poll(); // 정점 하나 꺼내기
            int X = current[0];
            int Y = current[1];

            for (int i = 0; i < 4; i++) {
                int nX = X + dx[i];
                int nY = Y + dy[i];

                // 좌표가 maps에서 벗어날 경우 다음 반복으로 넘어간다
                if (nX < 0 || nX > maps.length - 1 || nY < 0 || nY > maps[0].length - 1) {
                    continue;
                }

                // 아직 방문하지 않았고, 벽이 아닐 경우
                if (visited[nX][nY] == 0 && maps[nX][nY] == 1) {
                    visited[nX][nY] = visited[X][Y] + 1;
                    q.add(new int[]{nX, nY});
                }
            }
        }
    }
}

public class ROR {
	public static void main(String[] args) {
		int[][] maps= {{1,0,1,1,1},
						{1,0,1,0,1},
						{1,0,1,1,1},
						{1,1,1,0,1},
						{0,0,0,0,1}};
		Solu sol=new Solu();
		System.out.println(sol.solution(maps));
	}
}
