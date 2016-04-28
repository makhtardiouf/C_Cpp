#!/usr/bin/php
<?php

class ArrayUtils {

    public function intersect($arr1, $arr2) {
        $result = array();
        if (count($arr2) < count($arr1)) {
            list($arr2, $arr1) = array($arr1, $arr2);
        }
        foreach ($arr1 as $value) {
            if (in_array($value, $arr2)) {
                $result []= $value;
            }
        }
        return $result;
    }

}

class ProblemCase {

    private $answer1, $answer2;
    private $arrange1, $arrange2;

    public function __construct(&$input) {
        $this->answer1 = array_shift($input);
        $this->arrange1 = $this->readArrange($input);

        $this->answer2 = array_shift($input);
        $this->arrange2 = $this->readArrange($input);
    }

    private function readArrange(&$input) {
        $arrange = array();
        for ($i = 0; $i < 4; $i++) {
            $arrange []= array_shift($input);
        }
        return $arrange;
    }

    public function solve() {
        $row1 = split(" ", trim($this->arrange1[$this->answer1 - 1]));
        $row2 = split(" ", trim($this->arrange2[$this->answer2 - 1]));

        $intersect = ArrayUtils::intersect($row1, $row2);

        if (count($intersect) == 0) {
            return "Volunteer cheated!";
        }
        if (count($intersect) == 1) {
            return $intersect[0];
        }
        return "Bad magician!";
    }

}

class Problem {

    private $cases;

    public function __construct() {
        $this->cases = array();
    }

    public function addCase($case) {
        $this->cases []= $case;
    }

    public function solve() {
        $numCase = 1;
        foreach ($this->cases as $case) {
            $response = $case->solve();
            echo "Case #${numCase}: $response\n";
            $numCase++;
        }
    }

}

class ProblemReader {

    public static function read($inputLines) {
        $problem = new Problem();
        $numCases = array_shift($inputLines);

        for ($case = 1; $case <= $numCases; $case++) {
            $problem->addCase(new ProblemCase($inputLines));
        }

        return $problem;
    }

}

$problem = ProblemReader::read(file($argv[1]));
$problem->solve();
