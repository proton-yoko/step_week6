# step_week6

初心に帰ってC言語で書いてみた。

travel_all.c
ただの全探索。もっと綺麗にかけそう。

travel_greedy.c
一番近いのつなぐgreedyだけど、スタート場所によって結果が変わるからスタート場所は全部試してみた。
計算量はN倍になってしまうけど。

n=5 
travel_all.c 3291.621721

n=8 
travel_all.c 3778.715416

n=16　
travel_all.c さすがに時間かかりすぎる、でも結構待って途中経過で見つけたのが4765.810484
travel_greedy.c greedy for start=12 is 5065.575698

n=64
travel_greedy.c greedy for start=53 is 9276.223769

n=128
travel_greedy.c greedy for start=14 is 12084.319161

n=512
travel_greedy.c greedy for start=349 is 24191.660966

n=2048
travel_greedy.c greedy for start=285 is 47822.413446
