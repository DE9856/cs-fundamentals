set ns [new Simulator]
set nf [open lab33.nam w]
set tf [open lab33.tr w]

$ns namtrace-all $nf
$ns trace-all $tf

set n0 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]

$ns duplex-link $n0 $n3 1Mb 10ms DropTail
$ns make-lan "$n3 $n4 $n5 $n6 $n7 $n8" 512Kb 40ms LL Queue/DropTail Mac/802_3
$ns duplex-link-op $n0 $n3 orient right
$ns queue-limit $n0 $n3 20

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n7 $sink0
$ns connect $tcp0 $sink0
$tcp0 set packetSize_ 55

set ftpl [new Application/FTP]
$ftpl attach-agent $tcp0

set tfile [open cwnd.tr w]
$tcp0 attach $tfile
$tcp0 trace cwnd_

proc finish {} {
	global ns nf tf tfile
	$ns flush-trace
	close $nf
	close $tf
	close $tfile
	exec nam lab33.nam &
	exit 0
}

$ns at 0.1 "$ftpl start"
$ns at 5.0 "$ftpl stop"
$ns at 5.5 "finish"
$ns run
