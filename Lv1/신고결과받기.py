def solution(id_list, report, k):
    answer = [0 for _ in id_list]
    report_cnt = [0 for _ in id_list]
    user = ""
    user_report = ""
    # 중복 제거
    report = list(set(report)) 
    
    for rp in report:
        user, user_report = rp.split(" ")
        report_cnt[id_list.index(user_report)] += 1
        
    for rp in report:
        user, user_report = rp.split(" ")
        if report_cnt[id_list.index(user_report)] >= k:
            answer[id_list.index(user)] += 1
        
    return answer