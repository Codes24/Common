$(document).ready(function () {
	$("#register-form-area").hide();

	$("#btn-login").click(function () {
		$("#login-form").submit();
	})

	$("#btn-register").click(function () {
		$("#register-form").submit();
	})

	$("#btn-to-login").click(function () {
		$("#register-form-area").hide(1000);
		$("#login-form-area").show(1000);
	})

	$("#btn-to-register").click(function () {
		$("#login-form-area").hide();
		$("#register-form-area").show();
	})

})
