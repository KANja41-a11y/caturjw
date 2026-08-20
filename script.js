const points = document.querySelectorAll(".point");

const message = document.getElementById("message");
const turnText = document.getElementById("turnText");

const redPlayer = document.getElementById("redPlayer");
const bluePlayer = document.getElementById("bluePlayer");

const redScoreElement = document.getElementById("redScore");
const blueScoreElement = document.getElementById("blueScore");

const roundElement = document.getElementById("round");

const resetButton = document.getElementById("reset");

const modal = document.getElementById("modal");
const winnerText = document.getElementById("winner");
const winnerPiece = document.getElementById("winnerPiece");

const playAgain = document.getElementById("playAgain");


/*
  POSISI PAPAN

  0 ─── 1 ─── 2
  │  ╲  │  ╱  │
  3 ─── 4 ─── 5
  │  ╱  │  ╲  │
  6 ─── 7 ─── 8
*/


const winningLines = [

  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8],

  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],

  [0, 4, 8],
  [2, 4, 6]

];


const connectedPositions = {

  0: [1, 3, 4],

  1: [0, 2, 4],

  2: [1, 4, 5],

  3: [0, 4, 6],

  4: [0, 1, 2, 3, 5, 6, 7, 8],

  5: [2, 4, 8],

  6: [3, 4, 7],

  7: [4, 6, 8],

  8: [4, 5, 7]

};


let board = [

  "red",
  "red",
  "red",

  null,
  null,
  null,

  "blue",
  "blue",
  "blue"

];


let currentPlayer = "red";

let selectedPosition = null;

let gameFinished = false;

let redScore = 0;

let blueScore = 0;

let round = 1;


/*
  POSISI AWAL

  Baris awal tidak dihitung
  sebagai kemenangan.
*/

const startingLines = {

  red: [0, 1, 2],

  blue: [6, 7, 8]

};


/*
  CLICK POINT
*/

points.forEach((point) => {

  point.addEventListener("click", () => {

    const position =
      Number(point.dataset.position);

    handleClick(position);

  });

});


/*
  HANDLE CLICK
*/

function handleClick(position) {

  if (gameFinished) {
    return;
  }


  /*
    BELUM MEMILIH BIDAK
  */

  if (selectedPosition === null) {

    if (board[position] !== currentPlayer) {

      message.textContent =
        "Pilih bidak milikmu.";

      return;

    }


    selectPiece(position);

    return;
  }


  /*
    MEMILIH BIDAK LAIN
  */

  if (board[position] === currentPlayer) {

    selectPiece(position);

    return;

  }


  /*
    PINDAH KE TITIK KOSONG
  */

  if (board[position] === null) {

    const canMove =
      connectedPositions[selectedPosition]
        .includes(position);


    if (!canMove) {

      message.textContent =
        "Bidak tidak bisa bergerak ke titik tersebut.";

      return;

    }


    movePiece(
      selectedPosition,
      position
    );

    return;
  }


  message.textContent =
    "Titik tersebut sudah ditempati.";

}


/*
  SELECT PIECE
*/

function selectPiece(position) {

  clearSelection();

  selectedPosition = position;

  points[position]
    .classList.add("selected");


  connectedPositions[position]
    .forEach((destination) => {

      if (board[destination] === null) {

        points[destination]
          .classList.add("movable");

      }

    });


  message.textContent =
    "Pilih titik kosong untuk memindahkan bidak.";

}


/*
  MOVE PIECE
*/

function movePiece(from, to) {

  board[to] = board[from];

  board[from] = null;

  selectedPosition = null;

  clearSelection();

  render();


  const winner = checkWinner();


  if (winner) {

    finishGame(winner);

    return;

  }


  changeTurn();

}


/*
  CHANGE TURN
*/

function changeTurn() {

  currentPlayer =
    currentPlayer === "red"
      ? "blue"
      : "red";


  updateTurn();

}


/*
  UPDATE TURN
*/

function updateTurn() {

  const playerName =
    currentPlayer === "red"
      ? "Pemain 1"
      : "Pemain 2";


  turnText.textContent =
    playerName;


  redPlayer.classList.toggle(
    "active",
    currentPlayer === "red"
  );


  bluePlayer.classList.toggle(
    "active",
    currentPlayer === "blue"
  );


  message.textContent =
    `Giliran ${playerName}. Pilih bidakmu.`;

}


/*
  RENDER BOARD
*/

function render() {

  points.forEach((point, index) => {

    point.innerHTML = "";


    if (!board[index]) {
      return;
    }


    const piece =
      document.createElement("span");


    piece.classList.add(
      "piece",
      board[index]
    );


    point.appendChild(piece);

  });

}


/*
  CHECK WINNER
*/

function checkWinner() {

  for (const line of winningLines) {

    const [a, b, c] = line;


    if (

      board[a] !== null &&

      board[a] === board[b] &&

      board[a] === board[c]

    ) {

      const player =
        board[a];


      /*
        Jangan anggap posisi awal
        sebagai kemenangan.
      */

      const isStartingPosition =
        startingLines[player].every(
          (position) =>
            board[position] === player
        );


      if (isStartingPosition) {
        continue;
      }


      return {

        player: player,

        line: line

      };

    }

  }


  return null;

}


/*
  FINISH GAME
*/

function finishGame(result) {

  gameFinished = true;

  clearSelection();


  if (result.player === "red") {

    redScore++;

    redScoreElement.textContent =
      redScore;

    winnerText.textContent =
      "Pemain 1 Menang!";

    winnerPiece.className =
      "winner-piece red";

  }


  if (result.player === "blue") {

    blueScore++;

    blueScoreElement.textContent =
      blueScore;

    winnerText.textContent =
      "Pemain 2 Menang!";

    winnerPiece.className =
      "winner-piece blue";

  }


  result.line.forEach((position) => {

    points[position]
      .classList.add("selected");

  });


  modal.classList.add("show");

}


/*
  CLEAR SELECTION
*/

function clearSelection() {

  points.forEach((point) => {

    point.classList.remove(
      "selected",
      "movable"
    );

  });

}


/*
  RESET GAME
*/

function resetGame() {

  board = [

    "red",
    "red",
    "red",

    null,
    null,
    null,

    "blue",
    "blue",
    "blue"

  ];


  currentPlayer = "red";

  selectedPosition = null;

  gameFinished = false;


  modal.classList.remove("show");


  clearSelection();

  render();

  updateTurn();

}


/*
  NEXT ROUND
*/

playAgain.addEventListener(
  "click",
  () => {

    round++;

    roundElement.textContent =
      round;

    resetGame();

  }
);


/*
  FULL RESET
*/

resetButton.addEventListener(
  "click",
  () => {

    redScore = 0;

    blueScore = 0;

    round = 1;


    redScoreElement.textContent =
      "0";

    blueScoreElement.textContent =
      "0";

    roundElement.textContent =
      "1";


    resetGame();

  }
);


/*
  START GAME
*/

render();

updateTurn();
