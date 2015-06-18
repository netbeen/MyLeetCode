
/*

三层嵌套：
最内层：初始化变量
第二层：查询分数，set名次，set最后分数
最外层：删除部分属性以便满足题义。

*/

select Score, Rank
from
  (select Score, @currentRank:=@currentRank+if(Score=@lastScore,0,1) as Rank, @lastScore:=Score 
  from Scores, 
    (select @currentRank:=0, @lastScore:=NULL) as varInit 
  order by Score desc) as RankTable;
