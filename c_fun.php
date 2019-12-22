<?php
$start_time = microtime(true);
echo '<pre>';
for($i = 1;$i<=1000000;$i++){
        $a = $i+2;
        $b = $i*3;
        $c = $i+6;
        $re = getSolutionOVQE($a,$b,$c);
        //var_dump($re);
}
$end_time = microtime(true);
echo 'use time : '.($end_time-$start_time).' s';
exit;


