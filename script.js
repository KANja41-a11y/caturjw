const points = document.querySelectorAll(".point");

const statusElement = document.getElementById("status");
const turnText = document.getElementById("turnText");

const playerOne = document.getElementById("playerOne");
const playerTwo = document.getElementById("playerTwo");

const redScoreElement = document.getElementById("redScore");
const blueScoreElement = document.getElementById("blueScore");
const roundNumberElement = document.getElementById("roundNumber");

const resetButton = document.getElementById("resetButton");

const winnerModal = document.getElementById("winnerModal");
const winnerText = document.getElementById("winnerText");
const winnerPiece = document.getElementById("winnerPiece");
const nextRound = document.getElementById("nextRound");


/*
  0  1  2
  3  4  5
  6  7  8
*/

const WINNING_LINES = [
  [0, 1, 2],
  [3, 4, 5],
  [6, 7, 8],

  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],

  [0, 4, 8],
  [2, 4, 6]
];


/*
  Setiap titik terhubung dengan
  titik yang bersebelahan.
*/

const MOVES = {
  0: [1, 3, 4],
  1: [0, 2, 3, 4, 5],
  2: [1, 4, 5],

  3: [0, 1, 4, 6, 7],
  4: [0, 1, 2, 3, 5, 6, 7, 8],
  5: [1, 2, 4, 7, 8],

  6: [3, 4, 7],
  7: [3, 4, 5, 6, 8],
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

let selectedPiece = null;

let gameOver = false;

let redScore = 0;
let blueScore = 0;

let round = 1;


/*
  Posisi horizontal awal tidak dianggap
  sebagai kemenangan langsung.
*/

const INITIAL_LINES = {
  red: [0, 1, 2],
  blue: [6, 7, 8]
};


/*
  EVENT POINT
*/

points.forEach((point) => {

  point.addEventListener("click", () => {

    if (gameOver) {
      return;
    }

    const index = Number(point.dataset.index);

    handlePointClick(index);

  });

});


/*
  KLIK TITIK
*/

function handlePointClick(index) {

  /*
    Kalau belum memilih bidak,
    cari bidak milik pemain.
  */

  if (selectedPiece === null) {

    if (board[index] !== currentPlayer) {

      statusElement.textContent =
        "Pilih bidak milikmu terlebih dahulu.";

      return;
    }

    selectPiece(index);

    return;
  }


  /*
    Klik bidak lain milik pemain.
  */

  if (board[index] === currentPlayer) {

    selectPiece(index);

    return;
  }


  /*
    Kalau titik tujuan kosong,
    cek apakah bisa ditempati.
  */

  if (board[index] === null) {

    if (MOVES[selectedPiece].includes(index)) {

      movePiece(
        selectedPiece,
        index
      );

    } else {

      statusElement.textContent =
        "Bidak hanya dapat bergerak ke titik yang terhubung.";

    }

    return;
  }


  statusElement.textContent =
    "Titik tersebut sudah ditempati.";
}


/*
  PILIH BIDAK
*/

function selectPiece(index) {

  clearHighlights();

  selectedPiece = index;

  points[index].classList.add("selected");

  MOVES[index].forEach((destination) => {

    if (board[destination] === null) {

      points[destination].classList.add(
        "movable"
      );

    }

  });

  statusElement.textContent =
    "Pilih titik kosong untuk memindahkan bidak.";

}


/*
  PINDAHKAN BIDAK
*/

function movePiece(from, to) {

  board[to] = board[from];

  board[from] = null;

  selectedPiece = null;

  clearHighlights();

  renderBoard();

  const winner = checkWinner();

  if (winner) {

    finishGame(winner);

    return;
  }

  switchPlayer();

}


/*
  GANTI PEMAIN
*/

function switchPlayer() {

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

  turnText.textContent = playerName;

  playerOne.classList.toggle(
    "active",
    currentPlayer === "red"
  );

  playerTwo.classList.toggle(
    "active",
    currentPlayer === "blue"
  );

  statusElement.textContent =
    `Giliran ${playerName}. Pilih salah satu bidak.`;

}


/*
  RENDER BOARD
*/

function renderBoard() {

  points.forEach((point, index) => {

    point.innerHTML = "";

    const piece = board[index];

    if (!piece) {
      return;
    }

    const pieceElement =
      document.createElement("span");

    pieceElement.classList.add(
      "piece",
      piece
    );

    point.appendChild(pieceElement);

  });

}


/*
  CEK PEMENANG
*/

function checkWinner() {

  for (const line of WINNING_LINES) {

    const [a, b, c] = line;

    if (
      board[a] &&
      board[a] === board[b] &&
      board[a] === board[c]
    ) {

      const player = board[a];

      /*
        Posisi awal horizontal
        tidak dihitung sebagai kemenangan.
      */

      const isInitialLine =
        INITIAL_LINES[player].every(
          (position) =>
            board[position] === player
        );

      if (isInitialLine) {
        continue;
      }

      return {
        player,
        line
      };

    }

  }

  return null;

}


/*
  SELESAI
*/

function finishGame(result) {

  gameOver = true;

  clearHighlights();

  result.line.forEach((index) => {

    points[index].classList.add(
      "selected"
    );

  });


  if (result.player === "red") {

    redScore++;

    redScoreElement.textContent =
      redScore;

    winnerText.textContent =
      "Pemain 1 Menang!";

    winnerPiece.className =
      "red";

  } else {

    blueScore++;

    blueScoreElement.textContent =
      blueScore;

    winnerText.textContent =
      "Pemain 2 Menang!";

    winnerPiece.className =
      "blue";

  }


  winnerModal.classList.add(
    "show"
  );

}


/*
  RESET RONDE
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

  selectedPiece = null;

  gameOver = false;

  clearHighlights();

  renderBoard();

  updateTurn();

}


/*
  RONDE BERIKUTNYA
*/

function startNextRound() {

  round++;

  roundNumberElement.textContent =
    round;

  winnerModal.classList.remove(
    "show"
  );

  resetGame();

}


/*
  RESET BUTTON
*/

resetButton.addEventListener(
  "click",
  () => {

    round = 1;

    roundNumberElement.textContent =
      round;

    redScore = 0;
    blueScore = 0;

    redScoreElement.textContent = "0";
    blueScoreElement.textContent = "0";

    winnerModal.classList.remove(
      "show"
    );

    resetGame();

  }
);


/*
  NEXT ROUND
*/

nextRound.addEventListener(
  "click",
  startNextRound
);


/*
  HAPUS HIGHLIGHT
*/

function clearHighlights() {

  points.forEach((point) => {

    point.classList.remove(
      "selected",
      "movable"
    );

  });

}


/*
  START
*/

renderBoard();

updateTurn();
