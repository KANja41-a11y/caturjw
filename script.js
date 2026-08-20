// script.js


const slots = document.querySelectorAll(".slot");

const statusText = document.getElementById("status");

const turnName = document.getElementById("turnName");

const turnDot = document.getElementById("turnDot");

const redPlayer = document.getElementById("redPlayer");
const bluePlayer = document.getElementById("bluePlayer");

const redScoreText = document.getElementById("redScore");
const blueScoreText = document.getElementById("blueScore");

const roundText = document.getElementById("round");

const newGameButton = document.getElementById("newGame");

const winnerOverlay =
  document.getElementById("winnerOverlay");

const winnerName =
  document.getElementById("winnerName");

const winnerPiece =
  document.getElementById("winnerPiece");

const continueButton =
  document.getElementById("continueButton");


/*
    PAPAN

       0 ─── 1 ─── 2
       │  ╲  │  ╱  │
       3 ─── 4 ─── 5
       │  ╱  │  ╲  │
       6 ─── 7 ─── 8
*/


const winPatterns = [

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
    TITIK YANG SALING TERHUBUNG
*/

const neighbours = {

  0: [1, 3, 4],

  1: [0, 2, 4],

  2: [1, 4, 5],

  3: [0, 4, 6],

  4: [
    0, 1, 2,
    3, 5,
    6, 7, 8
  ],

  5: [2, 4, 8],

  6: [3, 4, 7],

  7: [4, 6, 8],

  8: [4, 5, 7]

};


/*
    POSISI AWAL
*/

const initialBoard = [

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


let board = [...initialBoard];

let currentPlayer = "red";

let selected = null;

let finished = false;

let redScore = 0;

let blueScore = 0;

let round = 1;


/*
    POSISI AWAL TIDAK LANGSUNG
    DIANGGAP SEBAGAI PEMENANG
*/

const initialLine = {

  red: [0, 1, 2],

  blue: [6, 7, 8]

};


/*
    EVENT CLICK
*/

slots.forEach(slot => {

  slot.addEventListener("click", () => {

    const id =
      Number(slot.dataset.id);

    play(id);

  });

});


/*
    LOGIKA PERMAINAN
*/

function play(id) {

  if (finished) {
    return;
  }


  /*
      BELUM MEMILIH BIDAK
  */

  if (selected === null) {

    if (board[id] !== currentPlayer) {

      statusText.textContent =
        "Itu bukan bidakmu. Pilih bidak sendiri.";

      return;
    }


    selectPiece(id);

    return;
  }


  /*
      MEMILIH BIDAK LAIN
  */

  if (board[id] === currentPlayer) {

    selectPiece(id);

    return;
  }


  /*
      TUJUAN HARUS KOSONG
  */

  if (board[id] !== null) {

    statusText.textContent =
      "Titik tersebut sudah ditempati.";

    return;
  }


  /*
      CEK APAKAH BISA BERGERAK
  */

  if (!neighbours[selected].includes(id)) {

    statusText.textContent =
      "Bidak hanya dapat bergerak ke titik yang terhubung.";

    return;
  }


  /*
      PINDAHKAN
  */

  board[id] = board[selected];

  board[selected] = null;

  selected = null;

  clearHighlights();

  render();


  /*
      CEK MENANG
  */

  const winner = getWinner();


  if (winner) {

    endRound(winner);

    return;
  }


  /*
      GANTI PEMAIN
  */

  changePlayer();

}


/*
    PILIH BIDAK
*/

function selectPiece(id) {

  clearHighlights();

  selected = id;

  slots[id].classList.add("selected");


  neighbours[id].forEach(target => {

    if (board[target] === null) {

      slots[target]
        .classList.add("available");

    }

  });


  statusText.textContent =
    "Sekarang pilih titik tujuan.";

}


/*
    GANTI PEMAIN
*/

function changePlayer() {

  currentPlayer =
    currentPlayer === "red"
      ? "blue"
      : "red";


  updatePlayerUI();

}


/*
    UPDATE UI PEMAIN
*/

function updatePlayerUI() {

  const redTurn =
    currentPlayer === "red";


  const name =
    redTurn
      ? "Merah"
      : "Biru";


  turnName.textContent = name;


  turnDot.style.background =
    redTurn
      ? "var(--red)"
      : "var(--blue)";


  turnDot.style.boxShadow =
    redTurn
      ? "0 0 0 5px rgba(185,78,78,.12)"
      : "0 0 0 5px rgba(72,107,136,.12)";


  redPlayer.classList.toggle(
    "active",
    redTurn
  );


  bluePlayer.classList.toggle(
    "active",
    !redTurn
  );


  statusText.textContent =
    `Giliran ${name}. Pilih bidakmu.`;

}


/*
    GAMBAR ULANG PAPAN
*/

function render() {

  slots.forEach((slot, index) => {

    slot.innerHTML = "";


    const color =
      board[index];


    if (!color) {
      return;
    }


    const piece =
      document.createElement("span");


    piece.className =
      `piece ${color}`;


    slot.appendChild(piece);

  });

}


/*
    CEK PEMENANG
*/

function getWinner() {

  for (const pattern of winPatterns) {

    const [a, b, c] = pattern;


    if (

      board[a] !== null &&

      board[a] === board[b] &&

      board[a] === board[c]

    ) {

      const player =
        board[a];


      /*
          Jangan hitung posisi awal
          sebagai kemenangan.
      */

      const isStartingLine =
        initialLine[player].every(
          index =>
            board[index] === player
        );


      if (isStartingLine) {
        continue;
      }


      return {

        player,

        pattern

      };

    }

  }


  return null;

}


/*
    PEMENANG
*/

function endRound(result) {

  finished = true;


  result.pattern.forEach(index => {

    const piece =
      slots[index].querySelector(".piece");


    if (piece) {

      piece.classList.add("winning");

    }

  });


  if (result.player === "red") {

    redScore++;

    redScoreText.textContent =
      redScore;

    winnerName.textContent =
      "Merah Menang!";

    winnerPiece.className =
      "winner-piece red";

  } else {

    blueScore++;

    blueScoreText.textContent =
      blueScore;

    winnerName.textContent =
      "Biru Menang!";

    winnerPiece.className =
      "winner-piece blue";

  }


  winnerOverlay.classList.add("show");

}


/*
    HAPUS HIGHLIGHT
*/

function clearHighlights() {

  slots.forEach(slot => {

    slot.classList.remove(
      "selected",
      "available"
    );

  });

}


/*
    MULAI RONDE BARU
*/

function nextRound() {

  board = [...initialBoard];

  currentPlayer = "red";

  selected = null;

  finished = false;

  round++;


  roundText.textContent =
    String(round).padStart(2, "0");


  winnerOverlay.classList.remove(
    "show"
  );


  clearHighlights();

  render();

  updatePlayerUI();

}


/*
    TOMBOL LANJUT
*/

continueButton.addEventListener(
  "click",
  nextRound
);


/*
    PERMAINAN BARU
    = SCORE KEMBALI 0
*/

newGameButton.addEventListener(
  "click",
  () => {

    redScore = 0;

    blueScore = 0;

    round = 1;


    redScoreText.textContent = "0";

    blueScoreText.textContent = "0";

    roundText.textContent = "01";


    board = [...initialBoard];

    currentPlayer = "red";

    selected = null;

    finished = false;


    winnerOverlay.classList.remove(
      "show"
    );


    clearHighlights();

    render();

    updatePlayerUI();

  }
);


/*
    START
*/

render();

updatePlayerUI();
