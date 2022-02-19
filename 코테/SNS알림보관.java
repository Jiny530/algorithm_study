import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public String[] solution(String[] records) {
        int checkNum = 0;
        Stack<String> noti = new Stack<String>(); 
        Queue<String> check = new LinkedList<String>(); 

        for (int i=0; i<records.length;i++){
            // 공백분할
            String[] newRoc = records[i].split("\\s+");

            if (newRoc[0].equals("check")){
                // 보관함으로 이동이면 최근꺼 꺼내서 보관
                String ch = noti.pop();
                check.offer(ch);
                checkNum++;
            }
            else { // 새로운 알림이면 이전 알림과 비교 후 보관
                if (noti.empty()) {
                    noti.push(records[i]);
                    continue;
                }
                String[] preNoti = noti.peek().split("\\s+");
                // 이전 알림과 같은 알림이면 이름 더하기
                if (preNoti[1].equals(newRoc[1]))  {
                    String newNoti = noti.pop();
                    newNoti += " " + newRoc[0]; 
                    noti.push(newNoti);
                }
                else { // 다른 알람이면 그냥 추가
                    noti.push(records[i]);
                }
            }
        }

        String[] answer = new String[checkNum];
        for(int i=0; i<checkNum;i++){
            String[] rec = check.poll().split("\\s+");
            switch(rec.length){
                case 2:
                answer[i] = rec[0];
                break;
                case 3:
                answer[i] = rec[0] + " and " + rec[2];
                break;
                default:
                answer[i] = rec[0] + " and " + (rec.length-2) + " others"; //Integer.toString(from);
            }

            if (rec[1].equals("share")) answer[i] += " shared your post";
            else if (rec[1].equals("comment")) answer[i] += " commented on your post";
        }
        return answer;
    }
}