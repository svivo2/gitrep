import torch
import torch.nn as nn

class MyLinearWithoutBiasFunction(torch.autograd.Function):
    """
    We can implement our own custom autograd Functions by subclassing
    torch.autograd.Function and implementing the forward and backward passes
    which operate on Tensors.
    """

    @staticmethod
    def forward(ctx, input, weights):
        # input is a N x C tensor, N is the batch size, C is the dimension of input
        # weights is a C x D tensor, C and D are the dimension out input and ouput
        ctx.save_for_backward(input, weights)
        outputs = torch.matmul(input, weights)
        return outputs
        # YOUR CODE HERE
        # return output of linear function


    @staticmethod
    def backward(ctx, grad_output):
        input, weights = ctx.saved_tensors
        input, weight = ctx.saved_tensors
        grad_input = torch.matmul(grad_output, weight.t())
        grad_weights = torch.matmul(input.t(), grad_output)

        return grad_input, grad_weights
        # YOUR CODE HERE
        # return grad_input, grad_weights, and grad_bias

class MyLinearWithoutBiasLayer(nn.Module):
  # You don't modify this layer
  def __init__(self, in_features = 2, out_features = 4):
    super(MyLinearWithoutBiasLayer, self).__init__()
    self.weights = nn.Parameter(torch.randn(in_features, out_features))

    self.linear_fn = MyLinearWithoutBiasFunction.apply
  def forward(self, input):
    return self.linear_fn(input, self.weights)


