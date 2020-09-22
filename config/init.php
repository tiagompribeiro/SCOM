<?php
    session_start();

    // init of  a session
  if (isset($_SESSION['message'])) {
    $_MESSAGE = $_SESSION['message'];
    unset($_SESSION['message']);
  }

?>
